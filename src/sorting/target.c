/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 17:48:32 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param src 
 * @param target 
 * @param best_target 
 * @param largest_elem 
 */

void	find_largest_and_best_target(t_stack *src, t_stack *target,
		t_stack **best_target, t_stack **largest_elem)
{
	int	min_diff;
	int	diff;

	min_diff = __INT_MAX__;
	*largest_elem = NULL;
	*best_target = NULL;
	while (target)
	{
		diff = src->value - target->value;
		if (!*largest_elem || target->value > (*largest_elem)->value)
			*largest_elem = target;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			*best_target = target;
		}
		target = target->next;
	}
}

/**
 * @brief 
 * 
 * @param src 
 * @param target 
 */

void	update_target(t_stack *src, t_stack *target)
{
	t_stack	*best_target;
	t_stack	*largest_elem;

	find_largest_and_best_target(src, target, &best_target, &largest_elem);
	if (best_target != NULL)
		src->target = best_target;
	else
		src->target = largest_elem;
}

/**
 * @brief 
 * 
 * @param source 
 * @param target 
 */

void	find_target(t_stack **source, t_stack **target)
{
	t_stack	*current_src;

	if (!source || !*source || !target || !*target)
		return ;
	current_src = *source;
	while (current_src)
	{
		update_target(current_src, *target);
		current_src = current_src->next;
	}
}
