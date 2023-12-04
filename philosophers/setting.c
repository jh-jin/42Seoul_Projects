/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:48:23 by jjin              #+#    #+#             */
/*   Updated: 2022/12/17 21:38:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		if (num > 2147483647 || num * sign < -2147483648)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (num * sign);
}

int	set_info(t_philo_info *philo_info, char **argv)
{
	philo_info->info_mutex = malloc(sizeof(pthread_mutex_t));
	if (philo_info->info_mutex == NULL)
		return (0);
	pthread_mutex_init(philo_info->info_mutex, NULL);
	philo_info->end = 0;
	philo_info->philo = ft_atoi(argv[1]);
	philo_info->die = ft_atoi(argv[2]);
	philo_info->eat = ft_atoi(argv[3]);
	philo_info->sleep = ft_atoi(argv[4]);
	philo_info->must_eat = 0;
	if (argv[5])
		philo_info->must_eat = ft_atoi(argv[5]);
	gettimeofday(&philo_info->start_time, NULL);
	if (philo_info->philo <= 0 || philo_info->die <= 0 || philo_info->eat <= 0
		|| philo_info->sleep <= 0 || philo_info->must_eat < 0)
		return (0);
	return (1);
}

int	set_fork(pthread_mutex_t **fork, int n)
{
	int	i;

	*fork = malloc(sizeof(pthread_mutex_t) * n);
	if (*fork == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&(*fork)[i], NULL);
		i++;
	}
	return (1);
}

int	set_philo(t_philo **philo, t_philo_info *info, pthread_mutex_t *fork)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->philo);
	if (philo == NULL)
		return (0);
	while (i < info->philo)
	{
		(*philo)[i].info = info;
		(*philo)[i].order = i;
		(*philo)[i].eat = 0;
		(*philo)[i].left_fork = &fork[i];
		(*philo)[i].right_fork = &fork[(i + 1) % info->philo];
		(*philo)[i].last_eat_time.tv_sec = info->start_time.tv_sec;
		(*philo)[i].last_eat_time.tv_usec = info->start_time.tv_usec;
		(*philo)[i].philo_mutex = malloc(sizeof(pthread_mutex_t));
		if ((*philo)[i].philo_mutex == NULL)
			return (0);
		pthread_mutex_init((*philo)[i].philo_mutex, NULL);
		(*philo)[i].status = 0;
		i++;
	}
	return (1);
}
