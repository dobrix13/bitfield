/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfield_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:34:32 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/04 02:31:47 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitfield.h"

uint64_t bit_field = 0;

void print_set_bits(uint64_t bit_field)
{
	int i = 0;
	while(i < 64)
	{
		if(IS_BIT_SET(bit_field, i))
			write(1, "+", 1);
		else
			write(1, ".", 1);
		i++;
	}
}



int main(void)
{
	SET_BIT(bit_field, 2);

	print_set_bits(bit_field);
	write(1, "\n", 1);
}