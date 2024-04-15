/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:10:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/15 16:33:46 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
* Check if we store correctly our input.
*/
void	print_tab(char **tab)
{
	int	w;

	w = 0;
	while (tab[w])
	{
		ft_printf("New word :");
		ft_printf("%s\n", tab[w]);
		w++;
	}
}
