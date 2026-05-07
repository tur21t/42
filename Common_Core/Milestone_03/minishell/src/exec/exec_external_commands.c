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

static char	*get_env_value(char **envp, char *name)
{
	int	len;
	int	i;

	len = ft_strlen(name);
	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], name, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

static char	*search_in_paths(char *cmd, char **paths)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths && paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin_free(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

static char	*find_executable(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*result;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path_env = get_env_value(envp, "PATH");
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	result = search_in_paths(cmd, paths);
	ft_free_split(paths);
	return (result);
}

/*int	exec_external_command(t_cmd *cmd, char **envp)
{
    pid_t	pid;
    int		status;
    char	*path;

    status = 0;
    if (!cmd || !cmd->args || !cmd->args[0])
        return (-1);
    path = find_executable(cmd->args[0], envp);
    if (!path)
    {
        command_not_found(cmd->args[0]);
        g_signal = 127;
        return (127);
    }
    pid = fork();
    if (pid == 0)
    {
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        execve(path, cmd->args, envp);
        perror("execve");
        if (errno == EACCES)
            exit(126);
        exit(127);
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            g_signal = WEXITSTATUS(status);
        else if (WIFSIGNALED(status))
            g_signal = 128 + WTERMSIG(status);
    }
    else
    {
        perror("fork");
        g_signal = 1;
    }
    free(path);
    return (g_signal);
}*/

int	exec_external_command(t_cmd *cmd, char **envp)
{
	char    *path;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (1);
	path = find_executable(cmd->args[0], envp);
	if (!path)
	{
		command_not_found(cmd->args[0]);
		return (127);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	execve(path, cmd->args, envp);
	perror("execve");
	free(path);
	if (errno == EACCES)
		return (126);
	return (127);
}
