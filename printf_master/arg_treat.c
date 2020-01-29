/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_treat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:52:45 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/28 00:31:42 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_chardup(char c)
{
	char	*ptr;

	if (!(ptr = ft_calloc(2, 1)))
		return (NULL);
	ptr[0] = c;
	return (ptr);
}

static char	*s_arg_is_null(va_list ap)
{
	char	*ptr;

	ptr = va_arg(ap, char*);
	if (ptr == NULL)
		return ("(null)");
	return (ptr);
}

char		*arg_treat(va_list ap, t_flarg *flarg)
{
	if (flarg->arg_type == 's')
		return (ft_strdup(s_arg_is_null(ap)));
	else if (flarg->arg_type == 'c')
		return (ft_chardup(va_arg(ap, int)));
	else if (flarg->arg_type == 'd' || flarg->arg_type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (flarg->arg_type == '%')
		return (ft_chardup('%'));
	else if (flarg->arg_type == 'p')
		return (ft_itoa_base(va_arg(ap, unsigned long),
			"0123456789abcdef"));
	else if (flarg->arg_type == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	else if (flarg->arg_type == 'x')
		return (ft_itoa_base(va_arg(ap, unsigned long long),
			"0123456789abcdef"));
	else if (flarg->arg_type == 'X')
		return (ft_itoa_base(va_arg(ap, unsigned long long),
			"0123456789ABCDEF"));
	else
		return (NULL);
}
