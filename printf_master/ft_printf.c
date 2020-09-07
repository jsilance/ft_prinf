/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:22:52 by jsilance          #+#    #+#             */
/*   Updated: 2020/03/11 02:33:45 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list ap;
	t_ret	ret;

	ret.char_skip = 0;
	ret.total_size = 0;
	if (!str || !*str)
		return (0);
	va_start(ap, str);
	while (str && str[ret.char_skip])
	{
		while (str && str[ret.char_skip] && str[ret.char_skip] != '%')
		{
			ft_putchar_fd(str[ret.char_skip++], 1);
			ret.total_size++;
		}
		if (str[ret.char_skip] == '%')
			if (ft_arg_typer(ap, &str[++ret.char_skip], &ret) == -1)
				return (-1);
	}
	va_end(ap);
	return (ret.total_size);
}
