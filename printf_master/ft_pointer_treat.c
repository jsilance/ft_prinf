/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 04:46:33 by jsilance          #+#    #+#             */
/*   Updated: 2020/02/21 03:26:28 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

void	ft_pointer_treat(t_flarg *flarg)
{
	if (!(flarg->flags & FLAG_MINUS))
		while (flarg->width-- && (flarg->total_len += 1))
			write(1, " ", 1);
	write(1, "0x", 2);
	flarg->total_len += 2;
	flarg->zero_len -= (flarg->zero_len > 1) ? 2 : flarg->zero_len;
	while (flarg->zero_len-- > 0 && (flarg->total_len += 1))
		write(1, "0", 1);
	(flarg->flags & FLAG_POINT && *flarg->arg_str == 48) ? (flarg->total_len--)
	: ft_putstr_fd(flarg->arg_str, 1);
	flarg->total_len += ft_strlen(flarg->arg_str);
	if (flarg->flags & FLAG_MINUS && *flarg->arg_str)
		while (flarg->width-- && (flarg->total_len += 1))
			write(1, " ", 1);
}
