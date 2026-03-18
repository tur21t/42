/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:19:48 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/25 19:32:28 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_ack_received = 0;

int	valid_pid(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	if (ft_atoi(s) <= 0)
		return (0);
	return (1);
}

static void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

int	setup_ack_handler(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = ack_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (0);
	return (1);
}

static void	send_bit_and_wait_ack(pid_t pid, int bit_val)
{
	g_ack_received = 0;
	if (bit_val)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	while (!g_ack_received)
		usleep(50);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
		send_bit_and_wait_ack(pid, (c >> bit--) & 1);
}
