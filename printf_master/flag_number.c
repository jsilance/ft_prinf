/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:46:12 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/29 04:17:57 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

#include <stdio.h>

static char	*zero_filler(t_flarg *flarg)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	if (!flarg->arg_str)
		return (ft_strdup(""));
	len = (flarg->zero_len) ? flarg->zero_len : flarg->sub_len;
	if (!(ptr = malloc(sizeof(char) * len + 1)))
		return (0);
	ptr[0] = (flarg->arg_str[0] == '-') ? '-' : 48;
	len -= (ptr[0] == '-') ? 0 : 1;
	len -= (flarg->arg_str[0]) ? 0 : 1;
	len += (flarg->flags & FLAG_POINT && ptr[0] == '-') ? 1 : 0;
	while (len--)
	{
		ptr[i] = (ptr[i] == '-') ? '-' : 48;
		i++;
	}
	ptr[i] = 0;
	while (flarg->arg_str && *flarg->arg_str)
		ptr[ft_strlen(ptr) - ft_strlen(flarg->arg_str)] =
			flarg->arg_str++[(ptr[0] == '-') ? 1 : 0];
	ptr[++i] = 0;
	return (ptr);
}

static char	*space_filler(t_flarg *flarg)
{
	char	*ptr;
	int		i;
	int		len;
	int		nb_space;

	i = 0;
	nb_space = flarg->width - ft_strlen(flarg->arg_str);
	len = ft_strlen(flarg->arg_str) + 1;
	ptr = ft_memstock(char_sizor(nb_space, 32), flarg->arg_str, 3, flarg->width);
	printf("");
	return (ptr);
}

void		flag_filler(t_flarg *flarg, int c)
{
	if (ft_strchr("uidxX%sp", flarg->arg_type) && c == 48 &&
		flarg->zero_len >= (int)ft_strlen(flarg->arg_str))
		flarg->arg_str = zero_filler(flarg);
	else if (c == 32)
		flarg->arg_str = space_filler(flarg);
}
