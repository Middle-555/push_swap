/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 14:46:42 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**

* @brief If they are 5 or more than 5 numbers to sort we push 2 time in stack b.
 * After this we can have a min and max value.
 *
 * @param stack_a
 * @param stack_b
 */

void	start_push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack_b(stack_a, stack_b);
	push_to_stack_b(stack_a, stack_b);
}

/**
 * @brief 
 * 
 * @param stack 
 */
void	find_index(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		median;

	temp = *stack;
	if (!temp)
		return ;
	i = 0;
	median = (stack_size(stack) / 2);
	while (temp)
	{
		temp->index = i;
		if (i >= median)
			temp->above_median = 1;
		else
			temp->above_median = 0;
		temp = temp->next;
		i++;
	}
}

/**
 * @brief 
 * 
 * @param stack_a 
 * @param stack_b 
 */
void	init_stack_for_sorting(t_stack **stack_a, t_stack **stack_b)
{
	find_index(stack_a);
	find_index(stack_b);
}
