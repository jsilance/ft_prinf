/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_typer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:07:32 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/29 00:12:09 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"
#include "ft_printf.h"

#include <stdio.h>

static void	t_flarg_init(t_flarg *flarg)
{
	flarg->flarg_len = 0;
	flarg->width = 0;
	flarg->sub_len = 0;
	flarg->zero_len = 0;
	flarg->flags = 0;
	flarg->arg_type = 'i';
	flarg->arg_str = NULL;
}

static void	flags_toi(char c, t_flarg *flarg)
{
	if (c == '0')
		flarg->flags |= FLAG_ZERO;
	else if (c == '-')
		flarg->flags |= FLAG_MINUS;
	else if (c == '.')
	{
		flarg->flags |= FLAG_POINT;
		if (flarg->flags & FLAG_ZERO)
			flarg->flags -= FLAG_ZERO;
	}
	else if (c == '%')
		flarg->flags |= (1 << 3);
}

static int	arg_c_typer(va_list ap, t_flarg *flarg, const char *str)
{
	int	i;

	if ((i = 0) || ft_strchr("0-.", str[i]))
	{
		flags_toi(str[i], flarg);
		if (*str == '0')
			i += zero_process(ap, &str[i + 1], flarg) + 1;
		else if (*str == '.')
			i += point_process(ap, &str[i + 1], flarg) + 1;
		else if (*str == '-')
			i += minus_process(ap, &str[i + 1], flarg) + 1;
	}
	else if (str[i] && ((ft_isdigit(str[i]) || str[i] == '*') &&
		(flarg->width = (str[i++] == '*') ? va_arg(ap, int) :
			ft_atoi(&str[i - 1]))))
	{
		if (flarg->width < 0 && (flarg->width *= -1))
			flarg->flags |= FLAG_MINUS;
		while (ft_isdigit(str[i]))
			i++;
	}
	flarg->flarg_len += i;
	return (i);
}

int		arg_typer(va_list ap, const char *str, t_ret *ret)
{
	t_flarg	flarg;
	int		i;
	int		zero;

	i = 0;
	zero = 1;
	if (!*str)
		return (-1) ;
	t_flarg_init(&flarg);
	while (*str && !(ft_strchr("scdipuxX%", *str)))
		if ((i = arg_c_typer(ap, &flarg, str)))
			str += i;
		else
			break ;
	flarg.arg_type = *str;
	flarg.arg_str = arg_treat(ap, &flarg);
	(flarg.arg_type == 'c' && !*flarg.arg_str && ret->total_size++) ?
		flarg.width-- : 0;
	flags_treat(&flarg);
	ret->total_size += flarg.width;
	free(flarg.arg_str);
	ret->char_skip += flarg.flarg_len + 1;
	return (zero);
}
