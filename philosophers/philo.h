/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:48:31 by jjin              #+#    #+#             */
/*   Updated: 2022/12/17 21:38:08 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_info
{
	int				end;
	int				philo;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	struct timeval	start_time;
	pthread_mutex_t	*info_mutex;
}	t_philo_info;

typedef enum e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_status;

typedef struct s_philo
{
	int				order;
	int				eat;
	t_status		status;
	pthread_t		pthread;
	t_philo_info	*info;
	struct timeval	last_eat_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*philo_mutex;
}	t_philo;

int		set_info(t_philo_info *philo_info, char **argv);
int		set_fork(pthread_mutex_t **fork, int n);
int		set_philo(t_philo **philo, t_philo_info *info, pthread_mutex_t *fork);
void	*loop(void *philo_n);
int		ft_atoi(const char *str);
int		monitoring(t_philo *philo, int philo_num);
int		check_end(t_philo_info *info);
int		waiting(long time);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);
int		check_end(t_philo_info *info);
int		check_die(t_philo *philo);
int		check_eat(t_philo *philo);
int		monitoring(t_philo *philo, int philo_num);
void	print(t_philo *philo);
void	start_loop(t_philo *philo, int philo_num);
void	set_status(t_philo *philo, t_status status);
long	getmilli(struct timeval time);

#endif
