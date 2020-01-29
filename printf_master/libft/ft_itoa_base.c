/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:40:49 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/28 00:36:49 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned int	ft_intlen(unsigned long long int n, size_t base)
{
	unsigned int	count_len;

	count_len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		count_len++;
	}
	return (count_len - 1);
}

char				*ft_itoa_base(unsigned long long int n, char *charset)
{
	unsigned long long int	intlen;
	size_t					count;
	char					*str;
	size_t					index;

	count = ft_strlen(charset);
	intlen = ft_intlen(n, count);
	index = 0;
	if (!(str = malloc(sizeof(char) * (intlen) + 1)))
		return (NULL);
	ft_bzero(str, intlen + 1);
	if (!n && (str[0] = 48))
		return (str);
	while (n > count)
	{
		str[intlen - index++] = charset[(n % count)];
		n /= count;
	}
	str[intlen - index] = charset[(n % count)];
	return (str);
}
