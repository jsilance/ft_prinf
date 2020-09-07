/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pourcent_treat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 04:12:15 by jsilance          #+#    #+#             */
/*   Updated: 2020/02/29 15:41:51 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_typer.h"

void	ft_pourcent_treat(t_flarg *flarg)
{
	if (!(flarg->flags & FLAG_MINUS))
		while (flarg->width-- && (flarg->total_len += 1))
			write(1, " ", 1);
	while (flarg->zero_len-- && (flarg->total_len += 1))
		write(1, "0", 1);
	write(1, "%", 1);
	flarg->total_len++;
	if (flarg->flags & FLAG_MINUS)
		while (flarg->width-- && (flarg->total_len += 1))
			write(1, " ", 1);
}
