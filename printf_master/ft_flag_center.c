/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 02:48:39 by jsilance          #+#    #+#             */
/*   Updated: 2020/03/11 03:23:55 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

static void	ft_string(t_flarg *flarg)
{
	if (flarg->width)
	{
		if (flarg->flags & FLAG_POINT)
			flarg->width -= ((int)ft_strlen(flarg->arg_str) < flarg->sub_len) ?
				ft_strlen(flarg->arg_str) : flarg->sub_len;
		else
			flarg->width -= ft_strlen(flarg->arg_str);
	}
	if (flarg->zero_len)
	{
		if (flarg->flags & FLAG_POINT)
		{
			flarg->width = flarg->zero_len - ft_strlen(flarg->arg_str);
			flarg->zero_len = 0;
		}
		else
			flarg->width -= ft_strlen(flarg->arg_str);
	}
}

static void	if_zero(t_flarg *f)
{
	int	old_zero_len;
	int	tmp;

	tmp = 0;
	old_zero_len = f->zero_len;
	if (f->flags & FLAG_POINT)
	{
		tmp = f->sub_len - ft_strlen(f->arg_str);
		f->zero_len = ((tmp < 0) ? 0 : tmp) + ((*f->arg_str == '-' && tmp >= 0)
				? 1 : 0);
		if (f->arg_type == '%')
			(f->arg_type == '%' && f->flags & FLAG_ZERO) ? (f->zero_len =
				old_zero_len - 1) : (f->zero_len = 0);
		if (f->width || *f->arg_str == '%')
			f->width -= old_zero_len + ft_strlen(f->arg_str) + f->zero_len -
				(*f->arg_str == '0' && f->flags & FLAG_POINT && !f->sub_len);
		else
			f->width = old_zero_len - ft_strlen(f->arg_str) - f->zero_len;
		f->flags |= FLAG_ZERO;
	}
	else
	{
		f->zero_len -= ft_strlen(f->arg_str);
		f->width -= ft_strlen(f->arg_str) + ((f->arg_type == 'p') ? 2 : 0);
	}
}

static void	ft_digital(t_flarg *f)
{
	if (f->sub_len)
	{
		if_zero(f);
		if (!(f->flags & FLAG_ZERO) && *f->arg_str != 48)
			f->sub_len -= ft_strlen(f->arg_str) -
				((ft_atoi(f->arg_str) < 0) ? 1 : 0);
		f->flags |= FLAG_ZERO;
		(f->zero_len > 0) ? 0 : (f->zero_len = 0);
		(f->flags & FLAG_POINT) ? 0 : (f->width -= ft_strlen(f->arg_str) +
			f->zero_len - (*f->arg_str == 48));
		f->sub_len = 0;
		(f->arg_type == 'p') ? 0 : (f->flags -= FLAG_POINT);
	}
	else
	{
		if_zero(f);
		(f->zero_len > 0) ? 0 : (f->zero_len = 0);
	}
}

void		ft_flag_center(t_flarg *flarg)
{
	if (ft_strchr("uidxX%", flarg->arg_type) && flarg->flags & 6 &&
		flarg->zero_len < 0)
	{
		flarg->flags |= FLAG_MINUS;
		flarg->width = -flarg->zero_len - ((flarg->arg_type == '%' &&
			flarg->flags & 6) ? 1 : 0);
		flarg->width += (flarg->arg_type == '%' && flarg->flags & 2) ? 1 : 0;
		flarg->zero_len = 0;
	}
	if (ft_strchr("sc", flarg->arg_type) || !ft_strchr("ps%uidxX",
		flarg->arg_type))
		ft_string(flarg);
	else if (ft_strchr("%puidxX", flarg->arg_type))
		ft_digital(flarg);
	(flarg->width < 0) ? (flarg->width = 0) : 0;
	(flarg->zero_len > 0) ? 0 : (flarg->zero_len = 0);
}
