/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:08:08 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/09 11:35:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned_decimal(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 0 && nb <= 9)
	{
		count += ft_putchar(nb + '0');
	}
	else
	{
		count += ft_printunsigned_decimal (nb / 10);
		count += ft_printunsigned_decimal (nb % 10);
	}
	return (count);
}
