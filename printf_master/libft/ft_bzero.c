/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:33:59 by jsilance          #+#    #+#             */
/*   Updated: 2020/02/07 02:04:16 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*tmp_str;

	if (!s)
		return ;
	count = 0;
	tmp_str = (unsigned char *)s;
	while (count < n)
		tmp_str[count++] = '\0';
}
