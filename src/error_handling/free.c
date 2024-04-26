/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:41:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 14:50:49 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param tab 
 */

void	free_tab(char **tab)
{
	int	w;

	w = 0;
	while (tab[w])
	{
		while (tab[w])
		{
			free(tab[w]);
			w++;
		}
	}
	free(tab);
}

/**
 * @brief 
 * 
 * @param lst 
 * @return * void 
 */

void	free_linked_list(t_stack *lst)
{
	t_stack	*temp;

	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

/**
 * @brief 
 * 
 * @param data 
 */

void	free_both_stack(t_data *data)
{
	free_linked_list(data->stack_a);
	free_linked_list(data->stack_b);
}
