/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 14:06:32 by dfrincu           #+#    #+#             */
/*   Updated: 2026/04/04 21:23:33 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_not_found(char *cmd)
{
	printf("%s: command not found\n", cmd);
}

void	replace_newlines_with_spaces(char *line)
{
    int i = 0;
    while (line && line[i])
    {
        if (line[i] == '\n')
            line[i] = ' ';
        i++;
    }
}

void	print_syntax_error(t_token *tokens)
{
	char *token = "newline";
	if (tokens)
	{
		if (tokens->type == T_PIPE || is_redir(tokens->type))
			token = tokens->value;
		else
		{
			while (tokens->next)
				tokens = tokens->next;
			if (tokens->type == T_PIPE || is_redir(tokens->type))
				token = "newline";
		}
	}
	printf("minishell: syntax error near unexpected token `%s'\n", token);
}

int	line_ends_with_pipe(const char *line)
{
    int i = strlen(line) - 1;
    while (i >= 0 && line[i] == ' ')
        i--;
    return (i >= 0 && line[i] == '|');
}

void	expand_vars_in_line(char **line, char **env)
{
    char	*expanded;

    expanded = expand_vars(*line, env);
    free(*line);
    *line = expanded;
}
