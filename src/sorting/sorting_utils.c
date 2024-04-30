/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:23 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 13:59:53 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Finds the node with the highest value in the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @return t_stack* Pointer to the node with the highest value. 
 * Returns NULL if the stack is empty.
 */

t_stack	*find_highest_node(t_stack **stack)
{
	t_stack	*highest;
	t_stack	*temp;
	long	highest_value;

	highest_value = LONG_MIN;
	highest = *stack;
	temp = *stack;
	while (temp != NULL)
	{
		if (highest_value < temp->value)
		{
			highest_value = temp->value;
			highest = temp;
		}
		temp = temp->next;
	}
	return (highest);
}

/**
 * @brief Finds the node with the lowest value in the stack.
 *
 * @param stack Pointer to the head of the stack.
 * @return t_stack* Pointer to the node with the lowest value. 
 * Returns NULL if the stack is empty.
 */

t_stack	*find_lowest_node(t_stack **stack)
{
	t_stack	*lowest;
	t_stack	*temp;
	long	lowest_value;

	lowest_value = LONG_MAX;
	lowest = *stack;
	temp = *stack;
	while (temp != NULL)
	{
		if (lowest_value > temp->value)
		{
			lowest_value = temp->value;
			lowest = temp;
		}
		temp = temp->next;
	}
	return (lowest);
}

/**
 * @brief Checks if the stack is sorted in ascending order.
 *
 * @param stack Pointer to the head of the stack.
 * @return int Returns 1 if the stack is not sorted, 0 if it is sorted.
 */

int	check_lst_sorted(t_stack **stack)
{
	t_stack	*current;

	if (!stack || !*stack)
		return (0);
	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
