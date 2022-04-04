/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:13:24 by avitolin          #+#    #+#             */
/*   Updated: 2022/02/24 01:49:01 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	Outputs the string ’s’ to the given file
**	descriptor.
*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
