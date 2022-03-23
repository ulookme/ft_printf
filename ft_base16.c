/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base16.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:33:24 by chajjar           #+#    #+#             */
/*   Updated: 2022/03/23 22:30:32 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen_base16(long long nb)
{
	long long	i;
	long long	number;
	int			neg;

	i = 0;
	number = 0;
	neg = 0;
	if (!nb)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
		number = nb;
	while (number)
	{
		number /= 16;
		i++;
	}
	return (i + neg);
}
