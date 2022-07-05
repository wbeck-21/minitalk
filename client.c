/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:12 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/05 15:47:35 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	get_char(char c, int pid)
{
	int	bit;

	bit = 0;
	while (++bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

void	send_msg(t_client_args *client_args)
{
	int	i;

	i = 0;
	while (client_args->msg[++i])
		get_char(client_args->msg[i], client_args->pid);
}

int	check_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[++i])
		if (argv[i] < '0' && argv[i] > '9')
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_client_args	client_args;

	if (argc == 3 && check_argv(argv[1]))
	{
		client_args.pid = ft_atoi(argv[1]);
		client_args.msg = argv[2];
		send_msg(&client_args);
		return (0);
	}
	ft_putstr_fd("Invalid CLI arguments", 2);
	return (1);
}
