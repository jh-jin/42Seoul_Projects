/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:55:34 by jjin              #+#    #+#             */
/*   Updated: 2022/10/06 21:18:37 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(char byte, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (byte >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(400);
		j--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_byte(str[i], pid);
}

void	usage(void)
{
	ft_putstr("usage: ./client [server-pid] [message]\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*msg;

	if (argc != 3)
		usage();
	server_pid = ft_atoi(argv[1]);
	msg = argv[2];
	send_message(msg, server_pid);
	return (0);
}
