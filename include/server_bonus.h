/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:30:49 by wbeck             #+#    #+#             */
/*   Updated: 2022/07/07 12:24:33 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_msg_char
{
	char	c;
	int		bit;
}	t_msg_char;

#endif