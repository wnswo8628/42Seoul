/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:38:43 by jugwak            #+#    #+#             */
/*   Updated: 2022/09/02 18:02:49 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_strdup(const char *str);
char	*ft_strchr(char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line_file(char *sentense, char *files);
char	*read_file(int fd, char *files);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif