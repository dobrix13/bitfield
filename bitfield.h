/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitfield.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <@students.42wolfsburg.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:05:11 by avitolin          #+#    #+#             */
/*   Updated: 2022/04/04 14:03:51 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIT_FIELD_H
#define BIT_FIELD_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>


#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define DEL_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)

#endif
