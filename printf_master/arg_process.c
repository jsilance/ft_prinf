/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 03:21:28 by jsilance          #+#    #+#             */
/*   Updated: 2020/02/29 18:43:20 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

static char	ft_type_finder(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (ft_strchr("scdpuixX%", str[i++]))
			return (*str);
	return (0);
}

int			ft_point_process(va_list ap, const char *str, t_flarg *flarg)
{
	int		i;
	char	type;

	i = 0;
	type = ft_type_finder(str);
	if (ft_strchr("uidxX%", type))
		return (ft_zero_process(ap, str, flarg));
	else
		flarg->sub_len = (str[i] == '*') ? va_arg(ap, int) : ft_atoi(&str[i]);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
		i++;
	if (i > 11)
		flarg->sub_len = 0;
	(flarg->sub_len < 0) ? flarg->flags -= FLAG_POINT : 0;
	flarg->sub_len *= (flarg->sub_len < 0) ? 0 : 1;
	return (i);
}

int			ft_minus_process(va_list ap, const char *str, t_flarg *flarg)
{
	int	i;

	i = 0;
	flarg->width = (str[i] == '*') ? va_arg(ap, int) : ft_atoi(&str[i]);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
		i++;
	if (i > 11)
		flarg->zero_len = 0;
	flarg->width *= (flarg->width < 0) ? -1 : 1;
	return (i);
}

int			ft_zero_process(va_list ap, const char *str, t_flarg *flarg)
{
	int	i;

	i = 0;
	if (!str[i] || *str == '0')
		return (i);
	if (!flarg->zero_len)
		flarg->zero_len = (str[i] == '*') ? va_arg(ap, int) : ft_atoi(&str[i]);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
		i++;
	if (i > 11)
		flarg->zero_len = 0;
	return (i);
}
