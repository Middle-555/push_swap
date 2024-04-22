/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:41:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 15:34:45 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

// test -> ok. 
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

void	free_both_stack(t_data *data)
{
	free_linked_list(data->stack_a);
	free_linked_list(data->stack_b);
}
