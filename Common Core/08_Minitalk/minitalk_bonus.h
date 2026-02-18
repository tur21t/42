/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:58:06 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/25 19:29:30 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

int		valid_pid(char *s);
int		setup_ack_handler(void);
void	send_char(int pid, char c);

#endif
