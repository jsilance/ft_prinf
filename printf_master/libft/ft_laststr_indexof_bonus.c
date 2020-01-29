/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_laststr_indexof_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:44:42 by jsilance          #+#    #+#             */
/*   Updated: 2019/10/17 01:47:49 by jsilance         ###   ########.fr       */
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

int			ft_last_indexof(char *str, char *needle)
{
	int	count;

	if (str && needle)
	{
		count = 0;
		while (ft_testchars(*str++, needle))
			count++;
		if (!ft_testchars(*str, needle))
			return (count);
	}
	return (-1);
}
