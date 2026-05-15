/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:51:26 by dfrincu           #+#    #+#             */
/*   Updated: 2026/05/13 15:51:38 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_iteration(t_token *tokens, t_cmd *cmds)
{
	if (cmds)
		free_cmds(cmds);
	if (tokens)
		free_tokens(tokens);
}

char	*get_user_input(void)
{
	char	*input;

	input = readline("minishell$ ");
	if (g_signal == SIGINT)
	{
		g_signal = 130;
		free(input);
		return (NULL);
	}
	return (input);
}

int	handle_multiline_eof(char **line, char quote, t_shell *shell)
{
	if (quote)
	{
		printf("minishell: unexpected EOF "
			"while looking for matching `%c'\n", quote);
		printf("minishell: syntax error: unexpected end of file\n");
		free(*line);
		*line = NULL;
		return (1);
	}
	printf("minishell: syntax error: unexpected end of file\n");
	printf("exit\n");
	free(*line);
	shell->last_exit = 2;
	return (2);
}
