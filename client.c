/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:02:05 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/05 02:26:12 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int i_x = 0;
/*
**	signal speed is controlled by usleep(500)
*/
void send_char(char c, pid_t server_pid)
{
	
	ft_putchar_fd(c , 1);
	int i = 8;

	while(i > 0)
	{
		if(IS_BIT_SET((u_int8_t)c, i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		ft_putnbr_fd(i, 1);
		usleep(500);
		
		i--;
	}
}

static void send_string(char *str, pid_t server_pid)
{
	
	while(str[i_x])
	{
		send_char(str[i_x], server_pid);
		i_x++;
	}
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		ft_putendl_fd("usage...", 1);
		return(0);
	}
	pid_t server_pid = ft_atoi(argv[1]);
	send_string(argv[2], server_pid);
	return(0);
}
