/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:49 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/05 20:39:08 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_msg_char
{
	char	c;
	int		bit;
}	t_msg_char;

void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);

#endif