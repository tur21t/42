/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:51:12 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/25 19:26:27 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3 || !valid_pid(argv[1]))
		return (ft_printf("Err21| valid command: ./client <PID> <text>\n"), 1);
	pid = (pid_t)ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
		return (ft_printf("Err21| Invalid PID\n"), 1);
	if (!setup_ack_handler())
		return (ft_printf("Err21| sigaction failed\n"), 1);
	str = argv[2];
	while (*str)
		send_char(pid, *str++);
	send_char(pid, '\0');
	return (0);
}
