/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 00:29:28 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/12 20:32:53 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_indexof(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		if (s[i++] == c)
			return (--i);
	return (-1);
}

char		*ft_strtrim(const char *s1, const char *charset)
{
	int		i;
	int		index_start;

	if (!s1 || !charset)
		return ((!s1) ? NULL : ft_strdup(s1));
	i = 0;
	index_start = 0;
	while (s1[i] && ft_indexof(charset, s1[i]) != -1)
		i++;
	index_start = i;
	i = ft_strlen(s1) - 1;
	if (index_start >= i)
		return (ft_strdup(""));
	while (s1[i] && ft_indexof(charset, s1[i]) != -1)
		i--;
	return (ft_substr(s1, index_start, i - index_start + 1));
}
