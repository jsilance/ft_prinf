/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_typer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:07:26 by jsilance          #+#    #+#             */
/*   Updated: 2020/03/11 02:34:17 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_TYPER_H
# define ARG_TYPER_H
# include "ft_printf.h"
# define FLAG_MINUS	1
# define FLAG_ZERO	2
# define FLAG_POINT	4

typedef struct	s_flarg
{
	int				flarg_len;
	int				width;
	int				sub_len;
	int				zero_len;
	int				total_len;
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

int				ft_arg_typer(va_list ap, const char *str, t_ret *ret);
void			ft_flags_treat(t_flarg *flarg);
char			*ft_arg_treat(va_list ap, t_flarg *flarg);

void			ft_flag_filler(t_flarg *flarg, int c);

int				ft_point_process(va_list ap, const char *str, t_flarg *flarg);
int				ft_minus_process(va_list ap, const char *str, t_flarg *flarg);
int				ft_zero_process(va_list ap, const char *str, t_flarg *flarg);

char			*ft_char_sizor(int nb, int c);
char			*ft_dectohex(unsigned long nb, char *str);
void			ft_flag_center(t_flarg *flarg);

void			ft_pourcent_treat(t_flarg *flarg);
void			ft_char_treat(t_flarg *flarg);
void			ft_pointer_treat(t_flarg *flarg);
void			ft_string_treat(t_flarg *flarg);
void			ft_number_treat(t_flarg *flarg);

#endif
