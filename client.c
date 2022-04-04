/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:02:05 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/04 17:31:02 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_bit(char c, pid_t server_pid)
{
	u_int8_t tmp = c;
	int i = 0;

	while(i < 8)
	{
		if(IS_BIT_SET(tmp, i))
			kill(server_pid, SIGUSR1);
		kill(server_pid, SIGUSR2);
		i++;
	}

}

void send_string(char *str, pid_t server_pid)
{
	int i = 0;
	while(str[i])
	{
		send_bit(str[i], server_pid);
		i++;
	}
}

int main(int argc, char **argv)
{
	char *str = NULL;
	if(argc != 3)
	{
		ft_putendl_fd("usage...", 1);
		return(0);
	}
	pid_t server_pid = ft_atoi(argv[1]);
	str = argv[2];
	send_string(str, server_pid);
	return(0);
}
