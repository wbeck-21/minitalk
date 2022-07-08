/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:16:09 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/07 19:04:27 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server_bonus.h"

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

static void	handler_msg(int sig, siginfo_t *info, void *context)
{
	static t_msg_char	chr = {0, 0};

	(void)context;
	if (sig == SIGUSR2)
		chr.c |= 1 << chr.bit;
	chr.bit++;
	if (chr.bit == 8)
	{
		write (1, &chr.c, 1);
		chr.c = 0;
		chr.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	struct sigaction	act;

	put_pid();
	write(1, "\n", 1);
	act.sa_handler = SIG_DFL;
	act.sa_sigaction = handler_msg;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
