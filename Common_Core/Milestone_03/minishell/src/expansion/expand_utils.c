/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:55:50 by dmtur             #+#    #+#             */
/*   Updated: 2026/04/07 20:56:00 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_surrounded_by_single_quotes(const char *str)
{
    if (!str)
        return (0);
    while (*str == ' ')
        str++;
    if (*str == '\'' && str[ft_strlen(str) - 1] == '\'')
        return (1);
    return (0);
}

static int	is_ws(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

/* "  2 \t   1  " -> "2 1" (solo para tokens sin comillas) */
static void	collapse_ws_inplace(char *s)
{
    int	r;
    int	w;
    int	seen_word;

    r = 0;
    w = 0;
    seen_word = 0;
    while (s[r] && is_ws(s[r]))
        r++;
    while (s[r])
    {
        if (is_ws(s[r]))
        {
            while (s[r] && is_ws(s[r]))
                r++;
            if (seen_word && s[r])
                s[w++] = ' ';
        }
        else
        {
            seen_word = 1;
            s[w++] = s[r++];
        }
    }
    s[w] = '\0';
}

void	expand_token_list(t_token *tokens, char **env)
{
    t_token	*curr;
    char	*expanded;

    curr = tokens;
    while (curr)
    {
        if (curr->type == T_HEREDOC && curr->next)
        {
            curr = curr->next->next;
            continue ;
        }
        if (curr->type == T_WORD && curr->quote != '\''
            && !is_surrounded_by_single_quotes(curr->value))
        {
            expanded = expand_vars(curr->value, env);
            free(curr->value);
            curr->value = expanded;
            if (curr->quote == 0 && curr->value)
                collapse_ws_inplace(curr->value);
        }
        curr = curr->next;
    }
}
