/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 23:37:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Determines the target index for placing a value from src in dst.
 *
 * Calculates where in the destination stack a value should go based on the
 * smallest difference in values. It recalculates indices before comparison.
 *
 * @param src Source stack containing the value to place.
 * @param dst Destination stack where the value needs to be placed.
 * @return int The index in dst where the value fits best.
 */

int	find_target_index(t_stack *src, t_stack *dst)
{
	int	min_diff;
	int	diff;
	int	best_dst;

	min_diff = __INT_MAX__;
	best_dst = dst->index;
	recalculate_index(src);
	recalculate_index(dst);
	if (src->value > find_highest_node(dst)->value)
		return (find_highest_node(dst)->index);
	else if (src->value < find_lowest_node(&dst)->value)
		return (find_highest_node(dst)->index);
	while (dst)
	{
		diff = src->value - dst->value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best_dst = dst->index;
		}
		dst = dst->next;
	}
	return (best_dst);
}

/**
 * @brief Determines the target index for placing a value from src in dst.
 *
 * Calculates where in the destination stack a value should go based on the
 * smallest positive difference in values between the source item and items in 
 * the destination.
 * Recalculates indices of both stacks before performing comparisons to ensure
 * that the indices are up to date.
 *
 * @param src Pointer to the source stack containing the value to place.
 * @param dst Pointer to the destination stack where the value needs 
 * to be placed.
 * @return int The index in dst where the value fits best based on minimum
 *  positive difference.
 */

int	find_target_index_in_a(t_stack *src, t_stack *dst)
{
	int	max_diff;
	int	diff;
	int	best_dst;

	best_dst = dst->index;
	max_diff = INT_MAX;
	recalculate_index(src);
	recalculate_index(dst);
	if (src->value > find_highest_node(dst)->value)
		return (find_lowest_node(&dst)->index);
	else if (src->value < find_lowest_node(&dst)->value)
		return (find_lowest_node(&dst)->index);
	while (dst)
	{
		diff = dst->value - src->value;
		if (diff > 0 && diff < max_diff)
		{
			max_diff = diff;
			best_dst = dst->index;
		}
		dst = dst->next;
	}
	return (best_dst);
}

/**
 * @brief Determines the best rotation operation to align stacks for 
 * optimal placement.
 *
 * This function finds the best rotational move required to align stack_b's top
 * element into its optimal position within stack_a. It calculates 
 * the target index
 * for stack_b's top in stack_a, and determines the least costly rotation to
 * perform this alignment. After calculating the cost, it executes the rotation.
 *
 * @param stack_a Double pointer to the first stack, usually the destination
 *  in rotations.
 * @param stack_b Double pointer to the second stack, from which the value 
 * is moved.
 * @return t_rotation A structure containing details about the rotation 
 * (e.g., steps in each stack).
 */

t_rotation	find_best_rotation(t_stack **stack_a, t_stack **stack_b)
{
	int			ind_a;
	int			ind_b;
	t_rotation	rotation_info;

	if (!*stack_b)
		return ((t_rotation){0, 0});
	ind_a = find_target_index_in_a(*stack_b, *stack_a);
	ind_b = 0;
	rotation_info = rotate_cost(stack_a, stack_b, ind_a, ind_b);
	exec_move(rotation_info, stack_a, stack_b);
	return (rotation_info);
}
