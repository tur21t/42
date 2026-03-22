/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_support02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:32:00 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/09 17:36:20 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	print_cmds(t_cmd *cmds)
{
	int		i;
	t_redir	*r;

	while (cmds)
	{
		printf("CMD:\n");
		i = 0;
		while (cmds->args && cmds->args[i])
		{
			printf("  arg[%d]: %s\n", i, cmds->args[i]);
			i++;
		}
		r = cmds->redirs;
		while (r)
		{
			printf("  redir: type %d, file %s\n", r->type, r->file);
			r = r->next;
		}
		cmds = cmds->next;
	}
}

void	free_redirs(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir->file);
		free(redir);
		redir = tmp;
	}
}

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*tmp;
	int		i;

	while (cmds)
	{
		tmp = cmds->next;
		if (cmds->args)
		{
			i = 0;
			while (cmds->args[i])
			{
				free(cmds->args[i]);
				i++;
			}
			free(cmds->args);
		}
		free_redirs(cmds->redirs);
		free(cmds);
		cmds = tmp;
	}
}

int	check_syntax(t_token *tokens)
{
	t_token	*prev;

	prev = NULL;
	if (!tokens)
		return (0);
	if (tokens->type == T_PIPE || is_redir(tokens->type))
		return (0);
	while (tokens)
	{
		if (tokens->type == T_PIPE)
		{
			if (!tokens->next || tokens->next->type == T_PIPE)
				return (0);
		}
		if (is_redir(tokens->type))
		{
			if (!tokens->next || tokens->next->type != T_WORD)
				return (0);
		}
		prev = tokens;
		tokens = tokens->next;
	}
	if (prev && (prev->type == T_PIPE || is_redir(prev->type)))
		return (0);
	return (1);
}
