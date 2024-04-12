/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:00:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/12 16:49:14 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_number(char **str)
{
	int	mot;
	int	caractere;

	mot = 0;
	while (str[mot])
	{
		caractere = 0;
		if (str[mot][caractere] == '-')
			caractere++;
		while (str[mot][caractere])
		{
			if (str[mot][caractere] >= '0' &&
			str[mot][caractere] <= '9' || str[mot][caractere] == '-')
				caractere++;
			else
				error_msg("You can only put number in the array !");
		}
	}
}


