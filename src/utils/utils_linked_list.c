/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/17 15:18:42 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*lst_new(t_stack *stack, int pos, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = pos;
	new_node->next = NULL;
	if (!stack)
		return (new_node);
	else
	{
		last = lst_last(stack);
		last->next = new_node;
		return (stack);
	}
}

void	fill_stack_a(char **tab, t_data *data)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		data->stack_a = lst_new(data->stack_a, i, ft_atoi(tab[i]));
		i++;
	}
	free_tab(tab);
}

t_stack	*lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst ->next;
	return (lst);
}

void	init_stack(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
}
