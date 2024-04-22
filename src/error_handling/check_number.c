/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:28:24 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 17:29:07 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_sign_and_number(char *str, char **tab)
{
	int	c;

	c = 0;
	if ((str[c] == '-' || str[c] == '+')
		&& (!(str[c + 1] >= '0' && str[c + 1] <= '9')))
	{
		free_tab(tab);
		error_msg("You need to put a number after - or +");
	}
	if (str[c] == '-' || str[c] == '+')
		c++;
	while (str[c])
	{
		if ((str[c] >= '0' && str[c] <= '9'))
			c++;
		else
		{
			free_tab(tab);
			error_msg("You can only put number in the array !");
		}
	}
}

void	check_number(char **tab)
{
	int	w;

	w = 0;
	while (tab[w])
	{
		check_sign_and_number(tab[w], tab);
		w++;
	}
}
