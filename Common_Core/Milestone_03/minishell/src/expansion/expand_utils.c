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

static void	free_token_chain(t_token *t)
{
    t_token	*n;

    while (t)
    {
        n = t->next;
        free(t->value);
        free(t);
        t = n;
    }
}

static t_token	*new_word_token_take(char *value, t_token *next)
{
	t_token	*t;

	t = malloc(sizeof(*t));
	if (!t)
	{
		free(value);
		return (NULL);
	}
	t->type = T_WORD;
	t->quote = 0;
	t->value = value; /* toma ownership */
	t->next = next;
	return (t);
}

/*int	is_surrounded_by_single_quotes(const char *str)
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

// "  2 \t   1  " -> "2 1" (solo para tokens sin comillas)
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
}*/

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

/*static t_token	*new_word_token(const char *value, t_token *next)
{
	t_token	*t;

	t = malloc(sizeof(*t));
	if (!t)
		return (NULL);
	t->type = T_WORD;
	t->quote = 0;
	t->value = ft_strdup(value);
	t->next = next;
	if (!t->value)
	{
		free(t);
		return (NULL);
	}
	return (t);
}*/

static void	delete_token(t_token **head, t_token *curr, t_token *prev)
{
	if (!head || !*head || !curr)
		return ;
	if (prev)
		prev->next = curr->next;
	else
		*head = curr->next;
	free(curr->value);
	free(curr);
}

/*
** Split curr->value (unquoted) into multiple tokens.
** Returns 1 if curr still exists, 0 if curr was deleted (no words).
*/
static int	split_token_words(t_token **head, t_token *curr, t_token *prev)
{
    char	*orig;
    t_token	*orig_next;
    int		i;
    int		start;
    int		first;
    int		replaced;
    t_token	*tail;
    char	*part;
    int		ok;

    if (!curr || !curr->value)
        return (1);

    orig = curr->value;
    orig_next = curr->next;
    i = 0;
    first = 1;
    replaced = 0;
    tail = curr;
    ok = 1;

    while (orig[i])
    {
        while (orig[i] && is_ws(orig[i]))
            i++;
        if (!orig[i])
            break ;
        start = i;
        while (orig[i] && !is_ws(orig[i]))
            i++;

        part = ft_substr(orig, start, i - start);
        if (!part)
        {
            ok = 0;
            break ;
        }
        if (first)
        {
            curr->value = part; /* curr ahora posee part */
            first = 0;
            replaced = 1;
        }
        else
        {
            t_token	*nt = new_word_token_take(part, tail->next);
            if (!nt)
            {
                ok = 0;
                break ;
            }
            tail->next = nt;
            tail = nt;
        }
    }

    if (!ok)
    {
        /* rollback si ya tocamos la lista */
        if (replaced)
        {
            free(curr->value);      /* libera el primer part */
            curr->value = orig;     /* restaurar */
            free_token_chain(curr->next); /* libera tokens añadidos */
            curr->next = orig_next; /* restaurar enlace */
        }
        return (1);
    }

    if (first)
    {
        /* expansión -> solo whitespace: borrar token y liberar orig dentro de delete_token */
        curr->value = orig;
        delete_token(head, curr, prev);
        return (0);
    }

    /* éxito: curr->value ya no es orig, así que liberamos orig */
    free(orig);
    return (1);
}

void	expand_token_list(t_token **tokens, char **env)
{
	t_token	*curr;
	t_token	*prev;
	char	*expanded;

	curr = *tokens;
	prev = NULL;
	while (curr)
	{
		// Skip heredoc delimiter token (the token after <<)
		if (curr->type == T_HEREDOC && curr->next)
		{
			prev = curr->next;
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
			{
				if (!split_token_words(tokens, curr, prev))
				{
					// curr was deleted; continue from next after prev
					curr = (prev) ? prev->next : *tokens;
					continue ;
				}
			}
		}
		prev = curr;
		curr = curr->next;
	}
}