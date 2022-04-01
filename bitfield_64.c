/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfield_64.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:34:32 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/01 15:57:29 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t bit_field = 0;

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define DEL_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)

void test_set_bits(uint64_t bit_field)
{
	int i = 0;
	while(i < 64)
	{
		if(IS_BIT_SET(bit_field, i))
			write(1, "+", 1);
		else
			write(1, "-", 1);
		i++;
	}
}

int main(void)
{
	SET_BIT(bit_field, 1);
	SET_BIT(bit_field, 4);
	SET_BIT(bit_field, 8);
	SET_BIT(bit_field, 7);
	SET_BIT(bit_field, 5);
	SET_BIT(bit_field, 63);
	SET_BIT(bit_field, 61);

	test_set_bits(bit_field);
	write(1, "\n", 1);
}