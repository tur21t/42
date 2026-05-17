/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_handle_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:46:53 by dfrincu           #+#    #+#             */
/*   Updated: 2026/05/13 15:47:01 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	parse_and_execute(t_token *tokens, t_shell *shell)
{
	t_cmd	*cmds;
	int		n_cmds;

	cmds = parse_tokens(tokens);
	if (!cmds)
		return ;
	n_cmds = init_pipeline(cmds);
	if (n_cmds == 1 && is_builtin(cmds->args[0]))
		execute(shell, cmds);
	else
		execute_pipeline(shell, cmds, n_cmds);
	free_cmds(cmds);
}

static int	handle_redir_before_heredoc(
	t_token **tokens, t_cmd *cmds, t_token **error_token, t_shell *shell)
{
	int		redir_status;
	t_token	*tmp;

	redir_status = check_redir_syntax_before_heredoc(*tokens, error_token);
	if (redir_status == 0)
	{
		cleanup_iteration(tokens, cmds);
		return (0);
	}
	else if (redir_status == 2)
	{
		tmp = *tokens;
		while (tmp && tmp != *error_token)
		{
			if (tmp->type == T_HEREDOC)
				apply_heredoc_token(tmp, shell);
			tmp = tmp->next;
		}
		cleanup_iteration(tokens, cmds);
		return (0);
	}
	return (1);
}

static int	handle_heredocs_and_syntax(
	t_token **tokens, t_cmd *cmds, t_shell *shell)
{
	(void)shell;
	if (!process_heredocs_and_check_syntax(*tokens))
	{
		cleanup_iteration(tokens, cmds);
		return (0);
	}
	if (!check_syntax(*tokens))
	{
		printf("minishell: syntax error near unexpected token `newline'\n");
		cleanup_iteration(tokens, cmds);
		return (0);
	}
	return (1);
}

void	handle_input(char *input, t_shell *shell)
{
	t_token	*tokens;
	t_cmd	*cmds;
	t_token	*error_token;
	int		ok;

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
		ok = handle_redir_before_heredoc(&tokens, cmds, &error_token, shell);
	if (ok)
		ok = handle_heredocs_and_syntax(&tokens, cmds, shell);
	if (ok)
		parse_and_execute(tokens, shell);
	cleanup_iteration(&tokens, cmds);
}
