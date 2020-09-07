/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 05:04:44 by jsilance          #+#    #+#             */
/*   Updated: 2020/02/15 05:36:49 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

void	ft_string_treat(t_flarg *flarg)
{
	int	len;

	len = (flarg->flags & FLAG_POINT &&
	flarg->sub_len < (int)ft_strlen(flarg->arg_str)) ?
	flarg->sub_len : ft_strlen(flarg->arg_str);
	if (!(flarg->flags & FLAG_MINUS))
		while (flarg->width-- && (flarg->total_len += 1))
			write(1, " ", 1);
	while (flarg->zero_len-- && (flarg->total_len += 1))
		write(1, "0", 1);
	write(1, flarg->arg_str, len);
	flarg->total_len += len;
	if (flarg->flags & FLAG_MINUS)
		while (flarg->width-- && (flarg->total_len += 1))
			write(1, " ", 1);
}
