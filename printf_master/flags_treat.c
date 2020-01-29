/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:31:46 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/29 03:49:04 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

char		*char_sizor(int nb, int c)
{
	char	*ptr;

	if (nb <= 0)
		return (strdup(""));
	if (!(ptr = malloc(sizeof(char) * nb + 1)))
		return (NULL);
	ft_memset(ptr, c, nb);
	ptr[nb] = 0;
	return (ptr);
}

static int	flag_point(t_flarg *flarg)
{
	char	*ptr;

	if (!flarg->sub_len && *flarg->arg_str == '0')
		flarg->arg_type = 's';
	if (flarg->flags & FLAG_POINT && flarg->arg_type == 's')
	{
		ptr = flarg->arg_str;
		flarg->sub_len *= (flarg->sub_len < 0) ? -1 : 1;
		flarg->arg_str = ft_substr(flarg->arg_str, 0, flarg->sub_len);
		free(ptr);
	}
	if (flarg->flags & FLAG_POINT && ft_strchr("uixXd%p", flarg->arg_type))
	{
		if (flarg->sub_len)
			flarg->zero_len = flarg->sub_len;
		flag_filler(flarg, 48);
		flarg->arg_type = (flarg->arg_type == 'p') ? 'p' : 's';
	}
	return (0);
}

static int	flag_zero(t_flarg *flarg)
{
	if (flarg->flags & FLAG_POINT)
	{
		flag_point(flarg);
		flag_filler(flarg, 32);
	}
	else if (flarg->flags & FLAG_ZERO)
		flag_filler(flarg, 48);
	return (0);
}

void		flags_treat(t_flarg *flarg)
{
	if (flarg->flags & FLAG_POINT)
		flag_point(flarg);
	(flarg->arg_type == 'p') ? flarg->arg_str = ft_strstock("0x",
		flarg->arg_str, 2) : 0;
	if (flarg->flags & FLAG_ZERO)
		flag_zero(flarg);
	(flarg->arg_type == 'p' && !flarg->arg_str) ? flarg->arg_str =
		ft_strstock("0x", flarg->arg_str, 2) : 0;
	if (flarg->width && flarg->flags & FLAG_MINUS)
		flarg->arg_str = ft_memstock(flarg->arg_str, char_sizor(flarg->width -
			ft_strlen(flarg->arg_str), 32), 3, ft_strlen(flarg->arg_str));
	else if (flarg->width && !(flarg->flags & FLAG_MINUS)){
		printf("rip {%s}\n", flarg->arg_str);
		flag_filler(flarg, 32);
		printf("rip {%s}\n", flarg->arg_str);
		}
	ft_putstr_fd(flarg->arg_str, 1);
}
