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
		cleanup_shell(shell, 1);
		exit(0);
	}
	if (*input)
		add_history(input);
	t_token *tokens = lexer(input);
	expand_token_list(tokens, shell->env);
	t_cmd *cmds = NULL;
	t_token *error_token = NULL;
	int redir_status = check_redir_syntax_before_heredoc(tokens, &error_token);
	if (redir_status == 0)
	{
    	free_tokens(tokens);
    	free(input);
    	return ;
	}
	if (redir_status == 2)
	{
    	// procesa todos los heredocs antes del error
    	t_token *tmp = tokens;
    	while (tmp && tmp != error_token)
    	{
        	if (tmp->type == T_HEREDOC)
            	apply_heredoc_token(tmp, shell);
        	tmp = tmp->next;
    	}
    	free_tokens(tokens);
    	free(input);
    	return ;
	}
	if (!process_heredocs_and_check_syntax(tokens))
    {
        free_tokens(tokens);
        free(input);
        return ;
    }
	if (!check_syntax(tokens))
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		free_tokens(tokens);
		free(input);
		return ;
	}
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
	int		skip_input;

	
	while (1)
	{
		skip_input = 0;
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
			{
				if (quote) 
				{
					printf("minishell: unexpected EOF while looking for matching `%c'\n", quote);
					printf("minishell: syntax error: unexpected end of file\n");
					free(line);
					skip_input = 1;
					break;
				} 
				else 
				{
				printf("minishell: syntax error: unexpected end of file\n");
				printf("exit\n");
				free(line);
				cleanup_shell(shell, 1);
				exit(2);
				}
			}
			tmp = ft_strjoin(line, "\n");
			free(line);
			line = ft_strjoin(tmp, input);
			free(tmp);
			free(input);
		}
		if (!skip_input)
		{
			replace_newlines_with_spaces(line);
			handle_input(line, shell);
		}
	}
}
