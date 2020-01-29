/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstock.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:12:14 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/28 02:27:38 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memstock(char *ptr, char *str, int fp, int len_ptr)
{
	char	*new_ptr;
	int		*i;

	i = (int[3]){ft_strlen(ptr), ft_strlen(str), 0};
	if (!(new_ptr = ft_calloc(sizeof(char), (i[0] + i[1]) + 1)))
		return (NULL);
	i[0] = 0;
	len_ptr = (len_ptr) ? len_ptr : 1;
	while ((!(i[1] = 0)) && ptr && ptr[i[0]] && len_ptr--)
	{
		new_ptr[i[0]] = ptr[i[0]];
		i[0]++;
	}
	new_ptr[i[0] + i[1]] = str[i[1]];
	while (str && str[i[1]++])
		new_ptr[i[0] + i[1]] = str[i[1]];
	if (ptr && (fp == 1 || fp == 3))
		free(ptr);
	if (ptr && (fp == 2 || fp == 3))
		free(str);
	return (new_ptr);
}
