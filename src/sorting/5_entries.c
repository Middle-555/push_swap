/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:09:42 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:21:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sorts a stack with exactly five elements.
 * 
 * Handles potentially reverse sorted stacks and sorts using a series of pushes
 * to a secondary stack and sorts the remaining smaller stack.
 * 
 * @param stack_a Main stack to sort.
 * @param stack_b Auxiliary stack used for temporary sorting.
 */

void	sort_5_entries(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest_node;
	int		size;

	if (reverse_sorted(*stack_a))
		Opti_5(stack_a, stack_b);
	else
	{
		size = stack_size(*stack_a);
		while (stack_size(*stack_a) > 3)
		{
			smallest_node = find_lowest_node(stack_a);
			while (*stack_a != smallest_node)
				rotate_stack_a(stack_a);
			push_to_stack_b(stack_a, stack_b);
		}
		sort_3_entries(stack_a);
		if (size == 5)
		{
			smallest_node = find_lowest_node(stack_b);
			if (*stack_b == smallest_node)
				swap_stack_b(stack_b);
			push_to_stack_a(stack_a, stack_b);
		}
		push_to_stack_a(stack_a, stack_b);
	}
}

/**
 * @brief Special case handling function for sorting specific configurations.
 * 
 * Executes a predefined series of operations including rotates, swaps, and
 * pushes to optimize sorting for a given initial stack configuration.
 * 
 * @param stack_a Main stack to operate on.
 * @param stack_b Auxiliary stack used for temporary sorting.
 */

void	case_5(t_stack **stack_a, t_stack **stack_b)
{
	rr_stack_a(stack_a);
	push_to_stack_b(stack_a, stack_b);
	swap_stack_a(stack_a);
	rotate_stack_a(stack_a);
	rotate_stack_a(stack_a);
	swap_stack_a(stack_a);
	push_to_stack_a(stack_a, stack_b);
}

/**
 * @brief Checks if a stack is in reverse order.
 * 
 * Returns 1 if the stack is sorted in decreasing order, 0 otherwise.
 * 
 * @param stack The stack to check.
 * @return int 1 if reverse sorted, 0 if not.
 */

int	reverse_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
