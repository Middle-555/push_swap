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
 * @brief
 *
 * @param src
 * @param dst
 * @return int
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

int	find_target_index_in_a(t_stack *src, t_stack *dst)
{
	int	max_diff;
	int	diff;
	int	best_dst;

	best_dst = dst->index;
	max_diff = INT_MAX;

	recalculate_index(src);
	recalculate_index(dst);
	//if (src->value > find_highest_node(dst)->value)
	//	return (find_highest_node(dst)->index + 1);
	//else if (src->value < find_lowest_node(&dst)->value)
		//return (find_lowest_node(&dst)->index);
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
