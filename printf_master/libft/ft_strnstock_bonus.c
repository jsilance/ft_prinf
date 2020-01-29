/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstock_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 02:57:58 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/26 07:21:43 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**	Concatene from the n first character from a mallocated sting[*1] and a
**	simple string to a new mallocated string, before return the adress of the
**	new mallocated string it free the inputed mallocated string[*1].
*/

char	*ft_strnstock(char *ptr, const char *str, size_t len, int f)
{
	char	*new_ptr;
	int		i[2];

	i[0] = 0;
	i[1] = 0;
	while (ptr && ptr[i[0]])
		i[0]++;
	while (str && str[i[1]] && i[1] < (int)len)
		i[1]++;
	if (!(new_ptr = malloc(sizeof(char) * (i[0] + i[1]) + 1)))
		return (NULL);
	i[0] = -1;
	i[1] = -1;
	while (ptr && ptr[++i[0]])
		new_ptr[i[0]] = ptr[i[0]];
	while (str && str[++i[1]] && i[1] < (int)len)
		new_ptr[i[0] + i[1]] = str[i[1]];
	new_ptr[i[0] + i[1]] = 0;
	if (f)
		free(ptr);
	return (new_ptr);
}
