/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:47:55 by jjin              #+#    #+#             */
/*   Updated: 2022/12/17 21:38:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

long	getmilli(struct timeval time)
{
	long	milli;

	milli = time.tv_sec * 1000;
	milli += time.tv_usec / 1000;
	return (milli);
}

void	set_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(philo->philo_mutex);
	philo->status = status;
	if (status == EATING)
		gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(philo->philo_mutex);
}

void	print(t_philo *philo)
{
	struct timeval	time;
	long			milli;
	const char		*arr[5] = {"has taken a fork", "is eating", "is sleeping",
		"is thinking", "died"};

	if (check_end(philo->info))
		return ;
	pthread_mutex_lock(philo->philo_mutex);
	gettimeofday(&time, NULL);
	milli = getmilli(time) - getmilli(philo->info->start_time);
	printf("%ld %d %s\n", milli, philo->order + 1, arr[(int)philo->status]);
	pthread_mutex_unlock(philo->philo_mutex);
}

void	free_all(t_philo_info *info, t_philo **philo, pthread_mutex_t **fork)
{
	int	i;
	int	n;

	n = info->philo;
	if (info->info_mutex)
		free(info->info_mutex);
	info->philo = 0;
	i = 0;
	while (i < n)
	{
		if (*fork)
			pthread_mutex_destroy(&(*fork)[i]);
		if (*philo && (*philo)[i].philo_mutex)
		{
			pthread_mutex_destroy((*philo)[i].philo_mutex);
			free((*philo)[i].philo_mutex);
		}
		i++;
	}
	if (*philo)
		free(*philo);
	*philo = 0;
	if (*fork)
		free(*fork);
	*fork = 0;
}

int	main(int argc, char **argv)
{
	t_philo_info	philo_info;
	t_philo			*philo;
	pthread_mutex_t	*fork;

	philo = 0;
	fork = 0;
	if (argc != 5 && argc != 6)
		return (0);
	if (set_info(&philo_info, argv) == 0
		|| set_fork(&fork, philo_info.philo) == 0
		|| set_philo(&philo, &philo_info, fork) == 0)
	{
		free_all(&philo_info, &philo, &fork);
		return (0);
	}
	start_loop(philo, philo_info.philo);
	free_all(&philo_info, &philo, &fork);
	return (0);
}
