/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 16:03:29 by kpourcel         ###   ########.fr       */
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

void	find_median(t_stack **stack)
{
	(*stack)->median = (stack_size(stack) / 2);
}
