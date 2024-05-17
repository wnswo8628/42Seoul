/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:40:04 by jugwak            #+#    #+#             */
/*   Updated: 2023/01/31 18:37:53 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>

void	printerror(char *message);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*get_path(char *cmd, char **env);
void	free_split(char **str);

#endif