/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsilance <jsilance@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:36:22 by jsilance          #+#    #+#             */
/*   Updated: 2020/01/29 00:49:23 by jsilance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    
    printf("[%d]\n", ft_printf("%5c", 0));
    printf("[%d]\n",    printf("%5c", 0));
    return (0);
}
