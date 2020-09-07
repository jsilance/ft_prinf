/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:24:01 by ssimon            #+#    #+#             */
/*   Updated: 2020/03/11 03:38:48 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dectohex(unsigned long nb, char *str)
{
	int		i;
	int		j;
	char	tab[25];
	char	*adress;

	i = 0;
	j = 0;
	if (nb == 0)
		tab[i++] = '0';
	while (nb != 0)
	{
		tab[i++] = str[nb % 16];
		nb /= 16;
	}
	if (!(adress = (char *)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (i > 0)
		adress[j++] = tab[i-- - 1];
	adress[j] = '\0';
	return (adress);
}
