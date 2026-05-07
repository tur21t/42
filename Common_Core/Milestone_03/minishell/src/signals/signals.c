/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:37:10 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/03 11:01:01 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sigint_handler(int sig)
{
	(void)sig;
	g_signal = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	//rl_done = 1;
}

void	init_signals(void)
{
	struct sigaction	sa;

	// Initialize the sigaction struct to zero
	ft_bzero(&sa, sizeof(sa));
	// Set handler for SIGINT (Ctrl+C)
	sa.sa_handler = sigint_handler;
	sigaction(SIGINT, &sa, NULL);
	// Set handler for SIGQUIT (Ctrl+\) - ignore it
	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}