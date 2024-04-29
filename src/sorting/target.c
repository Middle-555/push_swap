/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 16:00:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Finds the largest element and the best target element in the target
 * stack that has the smallest positive difference from the src element value.
 *
 * @param src Pointer to the current source stack element we are evaluating.
 * @param target Pointer to the target stack where we are searching for targets.
 * @param best_target Pointer to store the address of the best target element.
 * @param largest_elem Pointer to store the address of the largest element.
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
		printf("Checking target value: %d, src value: %d, diff: %d\n",
			target->value, src->value, diff);
		if (!*largest_elem || target->value > (*largest_elem)->value)
			*largest_elem = target;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			*best_target = target;
		}
		target = target->next;
	}
	if (*best_target)
		printf("Best target found: %d for source %d\n", (*best_target)->value,
			src->value);
	else
		printf("No suitable target found for source %d, using largest element %d\n", src->value, (*largest_elem) ? (*largest_elem)->value : -1);
}

/**
 * @brief Updates the target pointer of a source stack element to the best
 *        target found in the target stack, or to the largest element if no
 *        suitable target is found.
 *
 * @param src Pointer to the source stack element whose target is being updated.
 * @param target Pointer to the target stack used for finding the best target.
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
 * @brief Iterates over the source stack and updates the target for each element
 *        using the target stack to find the best match.
 *
 * @param source Pointer to the head of the source stack.
 * @param target Pointer to the head of the target stack.
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
