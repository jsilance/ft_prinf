/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:11:25 by jsilance          #+#    #+#             */
/*   Updated: 2019/11/11 15:06:11 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	d;
	size_t	needle_size;

	c = 0;
	if (!haystack || !needle)
		return (NULL);
	needle_size = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (haystack[c] && c < len)
	{
		d = 0;
		while (haystack[c + d] == needle[d] && needle[d] && (c + d) < len)
			d++;
		if (d == needle_size)
		{
			haystack += c;
			return ((char *)haystack);
		}
		c++;
	}
	return (NULL);
}
