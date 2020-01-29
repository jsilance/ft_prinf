/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 03:21:28 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/21 21:04:02 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

static char	type_finder(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (ft_strchr("scdpuixX%", str[i++]))
			return (*str);
	return (0);
}

int			point_process(va_list ap, const char *str, t_flarg *flarg)
{
	int		i;
	char	type;

	i = 0;
	type = type_finder(str);
	if (ft_strchr("uidxX%", type))
		return (zero_process(ap, str, flarg));
	else
		flarg->sub_len = (str[i] == '*') ? va_arg(ap, int) : ft_atoi(&str[i]);
	if (flarg->zero_len)
		flarg->width = flarg->zero_len * (flarg->zero_len < 0 ? -1 : 1);
	flarg->zero_len = 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
		i++;
	return (i);
}

int			minus_process(va_list ap, const char *str, t_flarg *flarg)
{
	int	i;

	i = 0;
	flarg->width = (str[i] == '*') ? va_arg(ap, int) : ft_atoi(&str[i]);
	if (flarg->width < 0)
		flarg->width *= -1;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
		i++;
	return (i);
}

int			zero_process(va_list ap, const char *str, t_flarg *flarg)
{
	int	i;

	i = 0;
	if (!str[i])
		return (i);
	flarg->zero_len = (str[i] == '*') ? va_arg(ap, int) : ft_atoi(&str[i]);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
		i++;
	return (i);
}
