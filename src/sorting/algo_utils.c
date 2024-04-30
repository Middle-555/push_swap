/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:35 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 13:29:53 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


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
