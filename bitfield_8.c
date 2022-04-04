/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfield_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 02:21:17 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/04 13:47:54 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitfield.h"
#include <stdio.h>

void print_set_bits(u_int8_t char_x)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if(IS_BIT_SET(char_x, i))
			write(1, "+", 1);
		else
			write(1, "-", 1);
		i++;
	}
}

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

void psb_string(char *str)
{
	int i = 0;
	while(str[i])
	{
		print_set_bits((u_int8_t)str[i]);
		binary_to_char((u_int8_t)str[i]);
		i++;
	}
}

int main(void)
{
	char *str = "Hello world";

	psb_string(str);
	write(1, "\n", 1);
	
}
