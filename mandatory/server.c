/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:09 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/05 20:58:37 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	put_pid(void)
{
	pid_t	pid;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
	{
		ft_putstr_fd("Error: ft_itoa()", 2);
		return ;
	}
	ft_putstr_fd(pid_str, 1);
}

static void	handler_msg(int sig)
{
	static t_msg_char	chr = {0, 0};

	if (sig == SIGUSR2)
		chr.c |= 1 << chr.bit;
	chr.bit++;
	if (chr.bit == 8)
	{
		write (1, &chr.c, 1);
		chr.c = 0;
		chr.bit = 0;
	}
}

static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	put_pid();
	signal(SIGUSR2, handler_msg);
	signal(SIGUSR1, handler_msg);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
