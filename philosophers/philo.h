/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:54:13 by jugwak            #+#    #+#             */
/*   Updated: 2023/04/08 22:54:15 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_info
{
	int				philo_cnt;
	long long		d_time;
	long long		e_time;
	long long		s_time;
	int				min_eat;
	int				isdead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	catchdrace;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				me;
	long long		last_eat;
	int				eat_cnt;
	int				eat_time;
	int				end_flag;
	long long		start_time;
	pthread_t		thread;
	pthread_mutex_t	*leftfork;
	pthread_mutex_t	*rightfork;
}	t_philo;

int			init_info(t_info *info, int ac, char **av);
t_philo		*set_philo(t_info *info);
int			init_mutex(t_info *info, t_philo *philo);
long long	get_time(void);
int			print_err(char *str, int errno);
long long	ft_atoi(const char *str);
void		philo_print(t_philo *philo, int me, char *str);
void		set_fork(t_philo *philo, t_info info);
void		philo_do(t_philo *philo);
int			make_thread(t_philo *philo, t_info *info);
void		ft_usleep(long long time);
void		waitforend(t_philo *philo, t_info info);

#endif