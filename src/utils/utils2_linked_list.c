/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:20:15 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/25 17:57:13 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*creade_new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	add_on_top(t_stack **stack, t_stack *new_node)
{
	new_node->next = *stack;
	*stack = new_node;
}

int	stack_size(t_stack **stack)
{
	t_stack	*temp;
	int		size;

	temp = *stack;
	size = 0;
	if (*stack == NULL)
		return (0);
	while (temp->next != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
