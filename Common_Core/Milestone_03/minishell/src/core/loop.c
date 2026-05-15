/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:35:31 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/03 11:00:18 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	concat_multiline(char **line, char *input)
{
	char	*tmp;

	tmp = ft_strjoin(*line, "\n");
	free(*line);
	*line = ft_strjoin(tmp, input);
	free(tmp);
	free(input);
}

static int	handle_multiline_input(char **line, t_shell *shell)
{
	char	*input;
	char	quote;
	int		status;

	quote = get_unclosed_quote(*line);
	while (quote || line_ends_with_pipe(*line))
	{
		input = readline("> ");
		if (!input)
		{
			status = handle_multiline_eof(line, quote, shell);
			return (status);
		}
		concat_multiline(line, input);
	}
	return (0);
}

static int	process_and_handle_line(char *line, t_shell *shell)
{
	char	*trimmed;

	replace_newlines_with_spaces(line);
	trimmed = ft_strtrim(line, " \t");
	free(line);
	if (!trimmed || trimmed[0] == '\0')
	{
		free(trimmed);
		return (0);
	}
	handle_input(trimmed, shell);
	free(trimmed);
	return (shell->should_exit);
}

static int	process_shell_iteration(t_shell *shell)
{
	char	*input;
	char	*line;
	int		status;

	input = get_user_input();
	if (!input)
	{
		printf("exit\n");
		return (1);
	}
	if (input[0] == '\0')
	{
		free(input);
		return (0);
	}
	line = ft_strdup(input);
	free(input);
	status = handle_multiline_input(&line, shell);
	if (status == 1)
		return (0);
	if (status == 2)
		return (2);
	if (process_and_handle_line(line, shell))
		return (1);
	return (0);
}

void	shell_loop(t_shell *shell)
{
	int	ret;

	while (1)
	{
		ret = process_shell_iteration(shell);
		if (ret == 1)
			break ;
		if (ret == 2)
			return ;
	}
}
