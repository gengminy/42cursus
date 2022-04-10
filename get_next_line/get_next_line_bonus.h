/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoh <knoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:25:11 by knoh              #+#    #+#             */
/*   Updated: 2022/03/27 15:25:13 by knoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <stdlib.h>

char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

char	*get_next_line(int fd);

#endif
