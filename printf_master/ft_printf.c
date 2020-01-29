/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:22:52 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/28 03:59:35 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list ap;
	t_ret	ret;

	ret.char_skip = 0;
	ret.total_size = 0;
	if (!str || !*str)
		return (-1);
	va_start(ap, str);
	while (str && str[ret.char_skip])
	{
		while (str && str[ret.char_skip] && str[ret.char_skip] != '%')
		{
			ft_putchar_fd(str[ret.char_skip++], 1);
			ret.total_size++;
		}
		if (str[ret.char_skip] == '%')
			arg_typer(ap, &str[++ret.char_skip], &ret);
	}
	va_end(ap);
	return (ret.total_size);
}

// tester avec "%100.*s%-178.%" ,-149,"$Z^u;7/k|=\f))k"
// si \0 rencontré dans une string ou comme char, ne rien faire apres
// si pointeur mais 0, renvoyer 0x
// souvent espace en trop
