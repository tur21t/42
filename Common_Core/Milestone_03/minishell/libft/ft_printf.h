/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:25:16 by dfrincu           #+#    #+#             */
/*   Updated: 2025/06/19 17:24:29 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	with_char(int c);
int	with_str(char *s);
int	with_int(int n);
int	with_unsigned(unsigned int n);
int	with_hex(unsigned int n, int uppercase);
int	with_ptr(unsigned long ptr);
#endif
