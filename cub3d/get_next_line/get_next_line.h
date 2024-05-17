/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:06:32 by jugwak            #+#    #+#             */
/*   Updated: 2023/07/10 20:06:34 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_strdup(const char *str);
char	*ft_strchr(char *str, int ch);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line_file(char *sentense, char *files);
char	*read_file(int fd, char *files);
char	*get_next_line(int fd);
size_t	ft_strlen2(const char *str);
char	*ft_substr2(char *s, unsigned int start, size_t len);

#endif
