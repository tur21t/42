/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:21:27 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/16 13:21:28 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_shell *shell, t_cmd *cmds)
{
    int	n_cmds;

    if (!cmds)
        return ;
    n_cmds = init_pipeline(cmds);
    if (n_cmds == 1 && cmds->args && cmds->args[0] && is_builtin(cmds->args[0]))
    {
        exec_builtin(shell, cmds);
        return ;
    }
    execute_pipeline(shell, cmds, n_cmds);
}

/*void	execute(t_shell *shell, t_cmd *cmds)
{
    int n_cmds;

    n_cmds = init_pipeline(cmds);
    if (n_cmds == 1)
    {
        if (is_builtin(cmds->args[0]))
            exec_builtin(shell, cmds);
        else
            exec_external_command(cmds, shell->env);
    }
    else
    {
        execute_pipeline(shell, cmds, n_cmds);
    }
}*/
