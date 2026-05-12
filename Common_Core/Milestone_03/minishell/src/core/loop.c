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

static void	cleanup_iteration(t_token *tokens, t_cmd *cmds)
{
    if (cmds)
        free_cmds(cmds);
    if (tokens)
        free_tokens(tokens);
}

/*static void	handle_input(char *input, t_shell *shell)
{
	int		n_cmds;
	t_token		*tokens;
	t_cmd		*cmds;
	t_token		*error_token;
	int			redir_status;
	int			ok;

	if (!input)
		return ;
	if (*input)
		add_history(input);
	tokens = lexer(input);
	cmds = NULL;
	error_token = NULL;
	ok = (tokens != NULL);
	if (ok)
		expand_token_list(&tokens, shell->env);
	if (ok)
	{
		redir_status = check_redir_syntax_before_heredoc(tokens, &error_token);
		if (redir_status == 0)
			ok = 0;
		else if (redir_status == 2)
		{
			t_token	*tmp;

			// procesa todos los heredocs antes del error 
			tmp = tokens;
			while (tmp && tmp != error_token)
			{
				if (tmp->type == T_HEREDOC)
					apply_heredoc_token(tmp, shell);
				tmp = tmp->next;
			}
			ok = 0;
		}
	}
	if (ok)
		ok = process_heredocs_and_check_syntax(tokens);
	if (ok && !check_syntax(tokens))
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		ok = 0;
	}
	if (ok)
	{
		cmds = parse_tokens(tokens);
		if (cmds)
		{
			n_cmds = init_pipeline(cmds);
			if (n_cmds == 1 && cmds->args && cmds->args[0]
				&& is_builtin(cmds->args[0]))
				execute(shell, cmds);
			else
				execute_pipeline(shell, cmds, n_cmds);
		}
	}
	cleanup_iteration(tokens, cmds);
}*/

static void	handle_input(char *input, t_shell *shell)
{
    int		n_cmds;
    t_token		*tokens;
    t_cmd		*cmds;
    t_token		*error_token;
    int			redir_status;
    int			ok;

    if (!input)
        return ;
    if (*input)
        add_history(input);
    tokens = lexer(input);
    cmds = NULL;
    error_token = NULL;
    ok = (tokens != NULL);
    if (ok)
        expand_token_list(&tokens, shell->env);
    if (ok)
    {
        redir_status = check_redir_syntax_before_heredoc(tokens, &error_token);
        if (redir_status == 0)
        {
            ok = 0;
            cleanup_iteration(tokens, cmds);
            return ;
        }
        else if (redir_status == 2)
        {
            t_token	*tmp;

            tmp = tokens;
            while (tmp && tmp != error_token)
            {
                if (tmp->type == T_HEREDOC)
                    apply_heredoc_token(tmp, shell);
                tmp = tmp->next;
            }
            ok = 0;
            cleanup_iteration(tokens, cmds);
            return ;
        }
    }
    if (ok)
        ok = process_heredocs_and_check_syntax(tokens);
    if (ok && !check_syntax(tokens))
    {
        printf("minishell: syntax error near unexpected token `newline'\n");
        ok = 0;
		cleanup_iteration(tokens, cmds);
		return ;
    }
    if (ok)
    {
        cmds = parse_tokens(tokens);
        if (cmds)
        {
            n_cmds = init_pipeline(cmds);
            if (n_cmds == 1 && cmds->args && cmds->args[0]
                && is_builtin(cmds->args[0]))
                execute(shell, cmds);
            else
                execute_pipeline(shell, cmds, n_cmds);
			free_cmds(cmds);
			cmds = NULL;
        }
    }
    cleanup_iteration(tokens, cmds);
}


void	shell_loop(t_shell *shell)
{
	char	*input;
	char	*line;
	char	*tmp;
	char	quote;
	int		skip_input;
	char	*trimmed;

	
	while (1)
	{
		skip_input = 0;
		input = readline("minishell$ ");
		if (g_signal == SIGINT)
		{
			g_signal = 130;
			free(input);
			continue;
		}
		if (!input)
		{
			printf("exit\n");
			//handle_input(NULL, shell);
			break ;
		}
		if (input[0] == '\0')
		{
			free(input);
			continue;
		}
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
				shell->last_exit = 2;
				return ;
				//cleanup_shell(shell, 1);
				//exit(2);
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
			trimmed = ft_strtrim(line, " \t");
			free (line);
			line = NULL;
			if (!trimmed || trimmed[0] == '\0')
			{
				free(trimmed);
				continue;
			}
			handle_input(trimmed, shell);
			free(trimmed);
			trimmed = NULL;
			if (shell->should_exit)
				break ;
		}
	}
}
