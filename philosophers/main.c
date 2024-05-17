/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:53:54 by jugwak            #+#    #+#             */
/*   Updated: 2023/04/08 22:53:57 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo, t_info info)
{
	int	i;

	i = -1;
	while (++i < info.philo_cnt)
		pthread_mutex_destroy(&info.forks[i]);
	pthread_mutex_destroy(&info.catchdrace);
	free(philo);
	free(info.forks);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;
	int		errno;

	errno = 0;
	if (init_info(&info, ac, av))
		errno = print_err("argument error", 3);
	if (errno)
		return (errno);
	if (!info.min_eat)
		return (0);
	philo = set_philo(&info);
	if (!philo)
		return (print_err("malloc error", 1));
	if (init_mutex(&info, philo))
		errno = print_err("mutex error", 1);
	if (errno)
		return (errno);
	errno = make_thread(philo, &info);
	if (errno)
		return (errno);
	free_all(philo, info);
	return (0);
}
