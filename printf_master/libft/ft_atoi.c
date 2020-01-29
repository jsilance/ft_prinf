/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:30:06 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/26 01:22:07 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		neg;
	int		cou;
	long	nbr;

	if (!str || !*str || (neg = 0))
		return (0);
	nbr = 0;
	cou = 0;
	while (str[cou] == '\t' || str[cou] == '\n' || str[cou] == '\r' ||
		str[cou] == '\v' || str[cou] == '\f' || str[cou] == ' ')
		cou++;
	neg = (str && str[cou] == '-');
	cou += (neg == 1 || str[cou] == '+');
	while ('0' <= str[cou] && str[cou] <= '9')
		if ((nbr = (nbr * 10) + (str[cou++] - 48)) < 0)
			return ((neg) ? -1 : 0);
	return ((neg == 1) ? -nbr : nbr);
}
