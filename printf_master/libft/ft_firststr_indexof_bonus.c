/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_firststr_indexof_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:45:00 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/11 14:22:46 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_testchars(char c, char *needle)
{
	while (*needle)
	{
		if (*needle == c)
			return (1);
		needle++;
	}
	return (0);
}

int			ft_first_indexof(char *str, char *needle)
{
	int	count;
	int	str_size;

	if (str && needle)
	{
		count = 0;
		str_size = (int)ft_strlen(str) - 1;
		str += str_size;
		while (ft_testchars(*str, needle))
		{
			str--;
			count++;
		}
		if (!ft_testchars(*str, needle))
			return (str_size - count);
	}
	return (-1);
}
