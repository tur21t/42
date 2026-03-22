/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:21:51 by dfrincu           #+#    #+#             */
/*   Updated: 2025/07/11 10:28:33 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif
# ifndef MAX_FD
#  define MAX_FD 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *rest);
char	*extract_line(char *rest);
char	*update_rest(char *rest);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strdup(const char *src);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcpy(char *dest, const char *src, size_t size);
#endif
