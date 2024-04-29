/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:35 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 16:07:19 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Searches for a given value in the stack and returns its index.
 *
 * This function iterates through the stack, starting from the head, to find the
 * first occurrence of a specified value. It returns the index of the element
 * where the value is found. If the value is not found, or if the stack is NULL,
 * the function returns -1.
 *
 * @param stack Pointer to the head of the stack. This must point to a valid and
 * initialized stack or be NULL.
 * @param value The integer value to search for in the stack.
 *
 * Operation:
 * - Checks if the stack pointer is NULL or points to an empty stack,
	immediately
 *   returning -1 if true.
 * - Iterates through each element of the stack, comparing the element's value
 *   to the target value.
 * - Returns the index of the first element that matches the target value. If no
 *   match is found by the end of the stack, returns -1.
 *
 * @return int The zero-based index of the first occurrence of the value, or -1
 * if the value is not found or the stack is NULL.
 */

int	find_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
		{
			return (index);
		}
		stack = stack->next;
		index++;
	}
	return (-1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_cost	initialize_cost(void)
{
	t_cost	cost;

	cost.ra = 0;
	cost.rra = 0;
	cost.rb = 0;
	cost.rrb = 0;
	cost.total_cost = 0;
	return (cost);
}
