/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:18:33 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sorts a large stack by alternating elements between two stacks.
 * 
 * Handles sorting by moving elements between stack_a and stack_b, sorting
 * them in stack_b, and then returning them in order to stack_a.
 * 
 * @param stack_a Primary stack of elements to be sorted.
 * @param stack_b Auxiliary stack for temporary storage during sorting.
 */

void	sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size_a;
	int	stack_size_b;

	push_to_stack_b(stack_a, stack_b);
	push_to_stack_b(stack_a, stack_b);
	stack_size_a = stack_size(*stack_a);
	while (stack_size_a > 3)
	{
		sorting(stack_a, stack_b);
		push_to_stack_b(stack_a, stack_b);
		stack_size_a = stack_size(*stack_a);
	}
	sort_3_entries(stack_a);
	stack_size_b = stack_size(*stack_b);
	while (stack_size_b > 0)
	{
		find_best_rotation(stack_a, stack_b);
		push_to_stack_a(stack_a, stack_b);
		stack_size_b = stack_size(*stack_b);
	}
	final_adjustment(stack_a);
}

/**
 * @brief Adjusts sorted stack so smallest element is at the top.
 * 
 * Rotates elements in stack_a until the smallest element is at the top.
 * Decides rotation direction based on smallest element's position.
 * 
 * @param stack_a Stack to adjust for smallest element at top.
 */

void	final_adjustment(t_stack **stack_a)
{
	while (*stack_a != find_lowest_node(stack_a))
	{
		if (find_lowest_node(stack_a)->index > (stack_size(*stack_a) / 2 + 1))
			rr_stack_a(stack_a);
		else
			rotate_stack_a(stack_a);
	}
}

/**
 * @brief Sorts elements between stacks based on optimal rotation cost.
 * 
 * Iterates through stack_a to evaluate movement costs for each element to
 * its target position in stack_b. Applies movement with lowest total cost.
 * 
 * @param stack_a Primary stack for element movement.
 * @param stack_b Auxiliary stack for optimal placement.
 */

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current_a;
	int			index_a;
	int			index_b;
	t_rotation	rot_cost;
	t_rotation	low_cost;

	current_a = *stack_a;
	index_a = 0;
	index_b = find_target_index(current_a, *stack_b);
	low_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
	while (current_a)
	{
		index_b = find_target_index(current_a, *stack_b);
		rot_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
		if (total_move(low_cost) > total_move(rot_cost))
			low_cost = rot_cost;
		current_a = current_a->next;
		index_a++;
	}
	exec_move(low_cost, stack_a, stack_b);
}
