/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 01:36:06 by avitolin          #+#    #+#             */
/*   Updated: 2022/02/24 01:45:42 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	compare two strings, returns 0 if strings are same or any other value 
**	if different
**	--------------------------------------------------------------------------*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
