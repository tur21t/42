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
	if (!input)
	{
		printf("exit\n");
		exit(0);
	}
	if (*input)
		add_history(input);
	t_token *tokens = lexer(input);
	if (check_syntax(tokens))
	{
		t_cmd *cmds = parse_tokens(tokens);
		execute(cmds, shell->env);
		print_cmds(cmds);
		free_cmds(cmds);
	}
	else
		printf("syntax error\n");
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
			free(input); // if needed
			continue;    // show prompt again
		}
		if (!input)
			handle_input(NULL, shell);
		line = ft_strdup(input);
		free(input);
	while ((quote = get_unclosed_quote(line)))
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
		handle_input(line, shell);
	}
}
