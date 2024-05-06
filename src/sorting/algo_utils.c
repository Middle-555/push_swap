/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:35 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:35:34 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Finds the index of a value within a stack.
 *
 * Iterates through the stack to locate the specified value and returns its
 * index. If the value is not found, returns -1.
 *
 * @param stack The stack to search.
 * @param value The value to find.
 * @return int Index of the value, or -1 if not found.
 */

int	find_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

/**
 * @brief Recalculates and updates the indices of all nodes in the stack.
 *
 * Iterates through the stack and assigns a new index to each node, starting
 * from 0 and incrementing by 1 for each node.
 *
 * @param stack The stack for which to recalculate indices.
 * @return int The total number of elements in the stack.
 */

int	recalculate_index(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		stack->index = index;
		index++;
		stack = stack->next;
	}
	return (index);
}
