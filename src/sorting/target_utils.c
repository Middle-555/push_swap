/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:16:54 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 16:57:25 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param node_a 
 * @param stack_b 
 */
void	find_highest_target_for_node(t_stack *node_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		target_index;

	current_b = stack_b;
	target = NULL;
	target_index = LONG_MIN;
	while (current_b)
	{
		if (current_b->value < node_a->value && current_b->value > target_index)
		{
			target_index = current_b->value;
			target = current_b;
		}
		current_b = current_b->next;
	}
	if (target_index == LONG_MIN)
		node_a->target = find_highest_node(stack_b);
	else
		node_a->target = target;
}
