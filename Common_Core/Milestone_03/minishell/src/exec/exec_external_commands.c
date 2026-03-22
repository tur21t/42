/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_external_commands.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:21:33 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/16 13:21:34 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_external_command(t_cmd *cmd, char **envp)
{
    pid_t	pid;
    int		status;
    char	*path;

    status = 0;
    if (!cmd || !cmd->args || !cmd->args[0])
        return (-1);
    path = ft_strjoin("/bin/", cmd->args[0]);
    pid = fork();
    if (pid == 0)
    {
        execve(path, cmd->args, envp);
        perror("execve");
        exit(127);
    }
    else if (pid > 0)
        waitpid(pid, &status, 0);
    else
        perror("fork");
    free(path);
    return (status);
}
