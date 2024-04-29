/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 17:23:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param src 
 * @param target 
 * @return int 
 */

int	find_target_index(t_stack *src, t_stack *target)
{
	int	min_diff;
	int	diff;
	int	best_target;

	min_diff = __INT_MAX__;
	if (src->value > find_highest_node(target)->value)
		return (find_index(&target, find_highest_node(target)->value));
	else if (src->value < find_lowest_node(target)->value)
		return (find_index(&target, find_highest_node(target)->value));
	while (target)
	{
		diff = src->value - target->value;
		printf("Checking target value: %d, src value: %d, diff: %d\n",
			target->value, src->value, diff);
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best_target = target->index;
		}
		target = target->next;
	}
	return (best_target);
}

