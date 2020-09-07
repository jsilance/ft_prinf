/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 05:38:10 by jsilance          #+#    #+#             */
/*   Updated: 2020/03/11 00:52:43 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

void	ft_number_treat(t_flarg *flarg)
{
	int	i;

	i = 0;
	if (!(flarg->flags & FLAG_MINUS))
		while (flarg->width-- > 0 && (flarg->total_len += 1))
			write(1, " ", 1);
	(flarg->arg_str[i] == '-') ? write(1, "-", ++i) : 0;
	while (flarg->zero_len-- > 0 && (flarg->total_len += 1))
		write(1, "0", 1);
	if (flarg->arg_str[i] == '0' && flarg->flags & FLAG_POINT)
	{
		if (!ft_strchr("xXudi", flarg->arg_type))
			ft_putchar_fd(' ', 1);
		else
			flarg->total_len--;
	}
	else
		write(1, &flarg->arg_str[i], ft_strlen(flarg->arg_str) -
			((*flarg->arg_str == '-') ? 1 : 0));
	flarg->total_len += ft_strlen(flarg->arg_str);
	if (flarg->flags & FLAG_MINUS)
		while (flarg->width-- > 0 && (flarg->total_len += 1))
			write(1, " ", 1);
}
