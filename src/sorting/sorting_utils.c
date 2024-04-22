/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:30:23 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 14:40:21 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_highest_node(t_stack **stack)
{
	t_stack	*highest;
	t_stack	*temp;
	int		highest_value;

	highest_value = INT_MIN;
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

t_stack	*find_lowest_node(t_stack **stack)
{
	t_stack	*lowest;
	t_stack	*temp;
	int		lowest_value;

	lowest_value = INT_MAX;
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

int	check_lst_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}
