/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:31 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/03 11:00:18 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_input(char *input, t_shell *shell)
{
	int	n_cmds;

	if (!input)
	{
		printf("exit\n");
		exit(0);
	}
	if (*input)
		add_history(input);
	t_token *tokens = lexer(input);
	expand_token_list(tokens, shell->env);
	t_cmd *cmds = NULL;
	//if (check_syntax(tokens))
    	cmds = parse_tokens(tokens);
	if (cmds)
	{
    		n_cmds = init_pipeline(cmds);
    		if (n_cmds > 1)
        		execute_pipeline(shell, cmds, n_cmds);
    		else
        		execute(shell, cmds);
    		free_cmds(cmds);
	}
	free_tokens(tokens);
	free(input);
}

void	shell_loop(t_shell *shell)
{
	char	*input;
	char	*line;
	char	*tmp;
	char	quote;

	while (1)
	{
		input = readline("minishell$ ");
		if (g_signal == SIGINT)
		{
			g_signal = 0;
			free(input);
			continue;
		}
		if (!input)
			handle_input(NULL, shell);
		line = ft_strdup(input);
		free(input);
		while ((quote = get_unclosed_quote(line)) || line_ends_with_pipe(line))
		{
			input = readline("> ");
			if (!input)
				break;
			tmp = ft_strjoin(line, "\n");
			free(line);
			line = ft_strjoin(tmp, input);
			free(tmp);
			free(input);
		}
		replace_newlines_with_spaces(line);
		handle_input(line, shell);
	}
}
