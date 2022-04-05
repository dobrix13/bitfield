/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:50:57 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/05 02:45:10 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

u_int8_t bf = 0;

void binary_to_char(u_int8_t bf)
{
	write(1, &bf, 1);
}


void handler(int n)
{
	static int i = 1;

	if(n == SIGUSR1)
	{
		SET_BIT(bf, i);
		ft_putchar_fd('+', 1);
		i++;
	}
	if(n == SIGUSR2)
	{
		i++;;
		ft_putchar_fd('.', 1);
	}
	if(i >= 8)
	{
		binary_to_char((u_int8_t)bf);
		i = 1;
		bf = 0;
		ft_putchar_fd('\n', 1);
	}
}

int main(void)
{
	pid_t pid = getpid();
	ft_putstr_fd(ft_itoa(pid), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while(1)
		pause();
}