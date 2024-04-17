/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:10:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/17 14:36:32 by kpourcel         ###   ########.fr       */
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

void	lst_print(t_stack *lst)
{
	while (lst != NULL)
	{
		ft_printf("value : %d\n", lst->value);
		lst = lst->next;
	}
}
