/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:53:48 by jugwak            #+#    #+#             */
/*   Updated: 2023/04/08 22:54:31 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	if (ft_atoi(av[1]) > 2147483647 || ft_atoi(av[1]) < 0)
		return (1);
	info->philo_cnt = ft_atoi(av[1]);
	info->d_time = ft_atoi(av[2]);
	info->e_time = ft_atoi(av[3]);
	info->s_time = ft_atoi(av[4]);
	info->isdead = 0;
	if (ac == 6)
	{
		if (ft_atoi(av[5]) > 2147483647 || ft_atoi(av[5]) < 0)
			return (1);
		info->min_eat = ft_atoi(av[5]);
	}
	else
		info->min_eat = -1;
	if (info->philo_cnt < 0 || info->d_time < 0 || \
		info->e_time < 0 || info->s_time < 0)
		return (1);
	return (0);
}

t_philo	*set_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = malloc(info->philo_cnt * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (++i < info->philo_cnt)
	{
		philo[i].info = info;
		philo[i].me = i;
		philo[i].eat_cnt = 0;
		philo[i].end_flag = 0;
		philo[i].start_time = get_time();
	}
	return (philo);
}

int	init_mutex(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&(info->catchdrace), NULL))
		return (1);
	info->forks = malloc(info->philo_cnt * sizeof(pthread_mutex_t));
	while (++i < info->philo_cnt)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (1);
	}
	i = -1;
	while (++i < info->philo_cnt)
	{
		philo[i].leftfork = &info->forks[i];
		philo[i].rightfork = &info->forks[(i + 1) % info->philo_cnt];
	}
	return (0);
}
