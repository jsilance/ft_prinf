/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_typer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:07:32 by jsilance          #+#    #+#             */
/*   Updated: 2020/03/11 02:34:35 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

static void	t_flarg_init(t_flarg *flarg)
{
	flarg->total_len = 0;
	flarg->flarg_len = 0;
	flarg->width = 0;
	flarg->sub_len = 0;
	flarg->zero_len = 0;
	flarg->flags = 0;
	flarg->arg_type = 'i';
	flarg->arg_str = NULL;
}

static void	ft_flags_toi(char c, t_flarg *flarg)
{
	if (c == '0')
		flarg->flags |= FLAG_ZERO;
	else if (c == '-')
		flarg->flags |= FLAG_MINUS;
	else if (c == '.')
		flarg->flags |= FLAG_POINT;
	else if (c == '%')
		flarg->flags |= (1 << 3);
}

static int	arg_c_typer(va_list ap, t_flarg *flarg, const char *str)
{
	int	i;

	if ((i = 0) || ft_strchr("0-.", str[i]))
	{
		ft_flags_toi(str[i], flarg);
		if (*str == '0')
			i += ft_zero_process(ap, &str[i + 1], flarg) + 1;
		else if (*str == '.')
			i += ft_point_process(ap, &str[i + 1], flarg) + 1;
		else if (*str == '-')
			i += ft_minus_process(ap, &str[i + 1], flarg) + 1;
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
	else if (str[i] == 32 && (i++))
		write(1, " ", 1);
	flarg->flarg_len += i;
	return (i);
}

int			ft_arg_typer(va_list ap, const char *str, t_ret *ret)
{
	t_flarg	flarg;
	int		i;

	ft_bzero((void*)&flarg, sizeof(t_flarg));
	i = 0;
	if (!*str)
		return (0);
	t_flarg_init(&flarg);
	while (*str && !(ft_strchr("scdipuxX%", *str)) && (ft_strchr(" *.-0", *str)
		|| ft_isdigit(*str)))
		if ((i = arg_c_typer(ap, &flarg, str)))
			str += i;
		else
			break ;
	flarg.arg_type = *str;
	flarg.arg_str = ft_arg_treat(ap, &flarg);
	(flarg.arg_type == 'c' && !*flarg.arg_str && ++ret->total_size) ?
		flarg.width-- : 0;
	(!ft_strchr("scdipuxX%", *str) && flarg.zero_len) ? flarg.zero_len-- : 0;
	ft_flags_treat(&flarg);
	ret->total_size += flarg.total_len;
	free(flarg.arg_str);
	ret->char_skip += flarg.flarg_len + 1;
	return (1);
}
