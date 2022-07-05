/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 10:20:37 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/05 15:46:50 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_client_args{
	int		pid;
	char	*msg;
}	t_client_args;

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);

#endif 