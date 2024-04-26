/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 14:50:49 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param str 
 */

void	error_msg(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(0);
}

/**
 * @brief 
 * 
 * @param tab 
 */

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
		{
			free_tab(tab);
			error_msg("please put valid number");
		}
		sign = 0;
		w++;
	}
}

/**
 * @brief 
 * 
 * @param tab 
 */

void	all_error_checking(char **tab)
{
	check_number(tab);
	int_checker(tab);
	check_duplicates(tab);
	sign_checking(tab);
}
