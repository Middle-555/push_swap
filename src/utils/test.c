/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:10:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/17 14:20:43 by kpourcel         ###   ########.fr       */
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
		// rajoute le pointeur ici & c'est un void (comme putstr ou putchar)
{
	while (lst != NULL) // la node apres ta derniere c'est NULL
	{
		ft_printf("value : %d\n", lst->value);
		lst = lst->next;
			// gere mieux le printf (je sais pas ce que c'est dans ta structure)
	}
}
