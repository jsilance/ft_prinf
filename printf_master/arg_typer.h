/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_typer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:07:26 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/28 03:44:52 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_TYPER_H
# define ARG_TYPER_H
# include "ft_printf.h"
# define FLAG_MINUS	(1<<0)
# define FLAG_ZERO	(1<<1)
# define FLAG_POINT	(1<<2)

#include <stdio.h>

typedef struct	s_flarg
{
	int				flarg_len;
	int				width;
	int				sub_len;
	int				zero_len;
	unsigned int	flags;
	char			*arg_str;
	char			arg_type;
	va_list			ap;
}				t_flarg;

typedef struct	s_ret
{
	int	char_skip;
	int	total_size;
}				t_ret;

int				arg_typer(va_list ap, const char *str, t_ret *ret);
void			flags_treat(t_flarg *flarg);
void			flag_filler(t_flarg *flarg, int c);
char			*arg_treat(va_list ap, t_flarg *flarg);
int				point_process(va_list ap, const char *str, t_flarg *flarg);
int				minus_process(va_list ap, const char *str, t_flarg *flarg);
int				zero_process(va_list ap, const char *str, t_flarg *flarg);
char			*char_sizor(int nb, int c);

#endif
