/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:42 by kpourcel          #+#    #+#             */
/*   Updated: 2023/11/03 10:50:38 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *src)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (src == NULL)
		return (write(1, "(null)", 6));
	while (src[i])
	{
		count += write(1, &src[i], 1);
		i++;
	}
	return (count);
}
