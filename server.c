/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:50:57 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/04 15:16:49 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void binary_to_char(u_int8_t bf)
{
	int i = 0;
	int n = 0;
	int tmp = 1;

	while(i < 8)
	{
		if(IS_BIT_SET(bf, i))
			n += tmp;
		tmp *= 2;
		i++;
	}
	printf("%d\n", n);
	write(1, &n, 1);
}


void handler(int n)
{
	static u_int8_t char_value = 0;
	static int i = 1;

	if(n == SIGUSR1)
	{
		SET_BIT(char_value, i);
		ft_putchar_fd('+', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	if(n == SIGUSR2)
	{
		i++;;
		ft_putchar_fd('.', 1);
		ft_putchar_fd('\n', 1);
	}
	if(i > 8)
	{
		binary_to_char((u_int8_t)char_value);
		i = 1;
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