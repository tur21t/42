/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:30:40 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/25 19:25:47 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_ack(pid_t client_pid)
{
	if (client_pid > 0)
		kill(client_pid, SIGUSR1);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static int				bit = 0;
	static unsigned char	c = 0;
	unsigned char			buf;

	(void)context;
	if (signum == SIGUSR2)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
		{
			buf = c;
			write(1, &buf, 1);
		}
		bit = 0;
		c = 0;
	}
	send_ack(info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server21 is waiting for your gentle actions.\n");
	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
