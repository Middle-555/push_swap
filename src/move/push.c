/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:50:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/19 15:13:58 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_stack **actual_stack, t_stack **dest_stack)
{
	t_stack	*node_to_move;
	t_stack	*new_node;

	node_to_move = actual_stack;
	new_node = creade_new_node(node_to_move->value);
	if (!new_node)
		return (NULL);
	*actual_stack = node_to_move->next;
	node_to_move->next = NULL;
	add_on_top(dest_stack, new_node);
	free(node_to_move);
	return ;
}

void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
	return ;
}

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
	return ;
}
