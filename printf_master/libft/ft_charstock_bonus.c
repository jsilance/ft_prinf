/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charstock_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 02:56:41 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/24 03:07:00 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Concatene from mallocated string[*1] and simple character to a new
**	mallocated string, before return the adress of the new mallocated string it
**	free the inputed mallocated string[*1].
*/

char	*ft_charstock(char *ptr, char str)
{
	char	*new_ptr;
	int		*i;

	i = (int[2]){0, 0};
	while (ptr && ptr[i[0]])
		i[0]++;
	i[0]++;
	if (!(new_ptr = malloc(sizeof(char) * (i[0] + 1))))
		return (NULL);
	i[0] = 0;
	while (ptr && ptr[i[0]])
		new_ptr[i[1]++] = ptr[i[0]++];
	new_ptr[i[1]++] = str;
	new_ptr[i[1]] = '\0';
	free(ptr);
	return (new_ptr);
}
