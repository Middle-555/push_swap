/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:00:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/15 18:09:55 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
 * w =  Word;
 * c =  caractere;
 */
void	check_number(char **tab)
{
	int	w;
	int	c;

	w = 0;
	while (tab[w])
	{
		c = 0;
		if (tab[w][c] == '-')
			c++;
		while (tab[w][c])
		{
			if ((tab[w][c] >= '0' && tab[w][c] <= '9') || tab[w][c] == '-')
				c++;
			else
				error_msg("You can only put number in the array !");
		}
		w++;
	}
}

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && 13 >= *str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && '9' >= *str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

void	int_checker(char **tab)
{
	int		i;
	long	nbr;

	i = 0;
	while (tab[i])
	{
		nbr = ft_atol(tab[i]);
		if (nbr <= -2147483647 || nbr >= 2147483647)
			error_msg("The value need to be an INT");
		i++;
	}
}
