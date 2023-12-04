/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:48:04 by jjin              #+#    #+#             */
/*   Updated: 2022/12/17 21:38:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_philo_info *info)
{
	int	result;

	pthread_mutex_lock(info->info_mutex);
	result = info->end;
	pthread_mutex_unlock(info->info_mutex);
	return (result);
}

int	check_die(t_philo *philo)
{
	struct timeval	now_time;
	struct timeval	last_eat_time;
	int				ret;

	ret = 0;
	pthread_mutex_lock(philo->philo_mutex);
	last_eat_time = philo->last_eat_time;
	gettimeofday(&now_time, NULL);
	if (getmilli(now_time) - getmilli(last_eat_time) >= philo->info->die)
	{
		philo->status = DEAD;
		ret = 1;
	}
	pthread_mutex_unlock(philo->philo_mutex);
	return (ret);
}

int	check_eat(t_philo *philo)
{
	int	ret;

	ret = 1;
	if (philo->info->must_eat == 0)
		return (0);
	pthread_mutex_lock(philo->philo_mutex);
	if (philo->eat < philo->info->must_eat)
		ret = 0;
	pthread_mutex_unlock(philo->philo_mutex);
	return (ret);
}

int	monitoring(t_philo *philo, int philo_num)
{
	int	i;
	int	stop;

	i = 0;
	stop = 0;
	while (i < philo_num)
	{
		if (check_die(&(philo[i])))
		{
			stop = 1;
			print(&(philo[i]));
			break ;
		}
		i++;
	}
	i = 0;
	while (i < philo_num && (check_eat(&(philo[i])) != 0))
		i++;
	if (i == philo_num)
		stop = 1;
	pthread_mutex_lock(philo[0].info->info_mutex);
	philo[0].info->end = stop;
	pthread_mutex_unlock(philo[0].info->info_mutex);
	return (stop);
}
