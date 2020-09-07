/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:31:46 by jsilance          #+#    #+#             */
/*   Updated: 2020/03/11 02:41:27 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

void	ft_flags_treat(t_flarg *f)
{
	if (f->zero_len < 0 && f->arg_type == '%')
	{
		f->width = -f->zero_len;
		f->flags |= FLAG_MINUS;
		f->flags -= FLAG_ZERO;
		f->zero_len = 0;
	}
	ft_flag_center(f);
	if (f->arg_type == 'c' || !ft_strchr("ps%uidxX", f->arg_type))
		ft_char_treat(f);
	else if (f->arg_type == 'p')
		ft_pointer_treat(f);
	else if (f->arg_type == 's')
		ft_string_treat(f);
	else if (ft_strchr("%uidxX", f->arg_type))
		ft_number_treat(f);
	else
	{
		f->total_len--;
		f->flarg_len--;
	}
}
