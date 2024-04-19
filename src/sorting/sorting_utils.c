/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:23 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/19 17:23:53 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_highest_node(t_stack **stack)
{
	t_stack	*highest;
	int		highest_value;

	highest_value = INT_MIN;
	highest = *stack;
	while (*stack != NULL)
	{
		if (highest_value < (*stack)->value)
		{
			highest_value = (*stack)->value;
			highest = *stack;
		}
		*stack = (*stack)->next;
	}
	return (highest);
}

t_stack	*find_lowest_node(t_stack **stack)
{
	t_stack	*lowest;
	int		lowest_value;

	lowest_value = INT_MAX;
	lowest = *stack;
	while (*stack != NULL)
	{
		if (lowest_value > (*stack)->value)
		{
			lowest_value = (*stack)->value;
			lowest = *stack;
		}
		*stack = (*stack)->next;
	}
	return (lowest);
}
