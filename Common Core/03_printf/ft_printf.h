/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:28:52 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/15 14:09:41 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

void	ft_putchar_pf(char c, size_t*counter);
void	ft_put_hex_pf(unsigned int n, size_t *counter, int uppercase);
void	ft_putnbr_pf(int n, size_t *counter);
void	ft_put_ptr_pf(void *ptr, size_t *counter);
void	ft_putstr_pf(char *s, size_t *counter);
void	ft_put_unsigned_pf(unsigned int n, size_t *counter);

#endif
