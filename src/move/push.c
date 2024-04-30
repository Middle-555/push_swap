/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:50:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 11:45:37 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param actual_stack 
 * @param dest_stack 
 */

void	push(t_stack **actual_stack, t_stack **dest_stack)
{
	t_stack	*node_to_move;
	t_stack	*new_node;

	node_to_move = *actual_stack;
	new_node = creade_new_node(node_to_move->value);
	if (!new_node)
		return ;
	*actual_stack = node_to_move->next;
	node_to_move->next = NULL;
	add_on_top(dest_stack, new_node);
	free(node_to_move);
	return ;
}

/**
 * @brief 
 * 
 * @param stack_a 
 * @param stack_b 
 */

void	push_to_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	recalculate_index(*stack_a);
	recalculate_index(*stack_b);
	ft_printf("pa\n");
	return ;
}

/**
 * @brief 
 * 
 * @param stack_a 
 * @param stack_b 
 */

void	push_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	recalculate_index(*stack_a);
	recalculate_index(*stack_b);
	ft_printf("pb\n");
	return ;
}
