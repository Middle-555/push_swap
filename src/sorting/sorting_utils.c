/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:23 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/19 17:17:25 by kpourcel         ###   ########.fr       */
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
