/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:46:12 by jsilance          #+#    #+#             */
/*   Updated: 2020/02/17 00:46:02 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

static char	*ft_zero_filler(t_flarg *flarg)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	if (!flarg->arg_str)
		return (ft_strdup(""));
	len = ((flarg->zero_len > flarg->sub_len) ? flarg->zero_len :
		flarg->sub_len);
	if (!(ptr = malloc(sizeof(char) * len + ft_strlen(flarg->arg_str) + 1)))
		return (0);
	(flarg->arg_str[0] == '-') ? ptr[i++] = '-' : 0;
	while (len-- > 0)
		ptr[i++] = 48;
	ptr[i] = 0;
	(*flarg->arg_str == '-') ? flarg->arg_str++ : 0;
	while (flarg->arg_str && *flarg->arg_str)
		ptr[i++] = *flarg->arg_str++;
	ptr[i] = 0;
	return (ptr);
}

static char	*ft_space_filler(t_flarg *flarg)
{
	char	*ptr;
	int		i;
	int		len;
	int		nb_space;

	i = 0;
	nb_space = flarg->width;
	len = ft_strlen(flarg->arg_str) + 1;
	ptr = ft_memstock(ft_char_sizor(nb_space, 32), flarg->arg_str, 3,
		flarg->width);
	return (ptr);
}

void		ft_flag_filler(t_flarg *flarg, int c)
{
	if (ft_strchr("uidxX%sp", flarg->arg_type) && c == 48)
		flarg->arg_str = ft_zero_filler(flarg);
	else if (c == 32)
		flarg->arg_str = ft_space_filler(flarg);
}
