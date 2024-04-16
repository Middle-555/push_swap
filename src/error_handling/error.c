/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/16 12:09:37 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error_msg(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(0);
}

void	sign_checking(char **tab)
{
	int	w;
	int	c;
	int	sign;

	w = 0;
	sign = 0;
	while (tab[w])
	{
		c = 0;
		while (tab[w][c])
		{
			if (tab[w][c] == '-')
				sign++;
			c++;
		}
		if (sign > 1)
			error_msg("please put valid number");
		sign = 0;
		w++;
	}
}

void	all_error_checking(char **tab)
{
	check_number(tab);
	int_checker(tab);
	check_duplicates(tab);
	sign_checking(tab);
}
