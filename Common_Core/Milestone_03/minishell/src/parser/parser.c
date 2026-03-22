/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:32:00 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/09 17:36:20 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_tokens(t_token *tokens)
{
	return (parse_pipeline(&tokens));
}

t_cmd	*parse_cmd(t_token **current)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	while (*current && (*current)->type != T_PIPE)
	{
		if ((*current)->type == T_WORD)
			add_arg(cmd, (*current)->value);
		else if (is_redir((*current)->type) && (*current)->next)
		{
			add_redir(cmd, *current, (*current)->next);
			*current = (*current)->next;
		}
		*current = (*current)->next;
	}
	return (cmd);
}

t_cmd	*parse_pipeline(t_token **current)
{
	t_cmd	*cmd;

	if (!*current)
		return (NULL);
	cmd = parse_cmd(current);
	if (*current && (*current)->type == T_PIPE)
	{
		*current = (*current)->next;
		cmd->next = parse_pipeline(current);
	}
	return (cmd);
}
