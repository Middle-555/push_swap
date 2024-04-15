/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:00:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/15 16:38:40 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
* w =  Word;
* c =  caractere;
*/
void	check_number(char **str)
{
	int	w;
	int	c;

	w = 0;
	while (str[w])
	{
		c = 0;
		if (str[w][c] == '-')
			c++;
		while (str[w][c])
		{
			if ((str[w][c] >= '0' && str[w][c] <= '9') || str[w][c] == '-')
				c++;
			else
				error_msg("You can only put number in the array !");
		}
		w++;
	}
}

