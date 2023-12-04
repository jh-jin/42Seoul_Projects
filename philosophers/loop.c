/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:48:11 by jjin              #+#    #+#             */
/*   Updated: 2022/12/17 21:38:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	waiting(long time)
{
	struct timeval	start_time;
	struct timeval	now_time;

	gettimeofday(&start_time, NULL);
	gettimeofday(&now_time, NULL);
	while (getmilli(now_time) - getmilli(start_time) < time)
	{
		usleep(500);
		gettimeofday(&now_time, NULL);
	}
	return (1);
}

int	eating(t_philo *philo)
{
	t_philo_info	*info;

	info = philo->info;
	pthread_mutex_lock(philo->left_fork);
	set_status(philo, FORK);
	print(philo);
	pthread_mutex_lock(philo->right_fork);
	print(philo);
	set_status(philo, EATING);
	print(philo);
	pthread_mutex_lock(philo->philo_mutex);
	philo->eat = philo->eat + 1;
	pthread_mutex_unlock(philo->philo_mutex);
	waiting(info->eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (1);
}

int	sleeping(t_philo *philo)
{
	t_philo_info	*info;

	info = philo->info;
	set_status(philo, SLEEPING);
	print(philo);
	waiting(info->sleep);
	return (1);
}

void	*loop(void *philo_n)
{
	t_philo	*philo;

	philo = (t_philo *)philo_n;
	if (philo->order % 2 == 1)
		usleep(500);
	while (1)
	{
		eating(philo);
		if (check_end(philo->info))
			break ;
		sleeping(philo);
		if (check_end(philo->info))
			break ;
		usleep(500);
		set_status(philo, THINKING);
		print(philo);
	}
	return (NULL);
}

void	start_loop(t_philo *philo, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_create(&(philo[i].pthread), NULL, loop, &(philo[i]));
		i++;
	}
	i = 0;
	while (1)
	{
		if (monitoring(philo, philo_num) == 1)
			break ;
	}
	while (i < philo_num)
	{
		pthread_mutex_unlock(philo[i].right_fork);
		pthread_mutex_unlock(philo[i].left_fork);
		pthread_join(philo[i].pthread, NULL);
		i++;
	}
}
