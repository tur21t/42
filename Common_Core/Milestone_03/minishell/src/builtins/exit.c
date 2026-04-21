/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:05:40 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/22 21:05:49 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"
#include <unistd.h>

static int	is_numeric(const char *s)
{
    int	i;

    i = 0;
    if (!s || !s[0])
        return (0);
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (!ft_isdigit(s[i]))
        return (0);
    while (s[i])
    {
        if (!ft_isdigit(s[i]))
            return (0);
        i++;
    }
    return (1);
}

int	builtin_exit(char **args)
{
    write(1, "exit\n", 5);
    if (!args || !args[1])
        exit(g_signal);
    if (!is_numeric(args[1]))
    {
        write(2, "minishell: exit: ", 17);
        write(2, args[1], ft_strlen(args[1]));
        write(2, ": numeric argument required\n", 28);
        exit(2);
    }
    if (args[2])
    {
        write(2, "minishell: exit: too many arguments\n", 36);
        return (1);
    }
    exit((unsigned char)ft_atoi(args[1]));
    return (0);
}
