/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:38:25 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/03 17:39:35 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief
 *
 * @param stack
 */

void	entries_handler(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size_a;
	int	stack_size_b;

	stack_size_a = stack_size(*stack_a);
	if (stack_size_a == 2)
		sort_2_entries(stack_a);
	else if (stack_size_a == 3)
		sort_3_entries(stack_a);
	else if (stack_size_a == 4)
	{
		push_to_stack_b(stack_a, stack_b);
		sort_3_entries(stack_a);
		push_to_stack_a(stack_a, stack_b);
		while (*stack_a != find_lowest_node(stack_a))
		{
			if (find_lowest_node(stack_a)->index > stack_size(*stack_a))
				rr_stack_a(stack_a);
			else
				rotate_stack_a(stack_a);
		}
	}
	else if (stack_size_a == 5)
		sort_5_entries(stack_a, stack_b);
	else if (stack_size_a > 5)
	{
		push_to_stack_b(stack_a, stack_b);
		push_to_stack_b(stack_a, stack_b);
		stack_size_a = stack_size(*stack_a);
		while (stack_size_a > 0)
		{
			sorting(stack_a, stack_b);
			push_to_stack_b(stack_a, stack_b);
			stack_size_a = stack_size(*stack_a);
		}
		stack_size_b = stack_size(*stack_b);
		while (stack_size_b > 0)
		{
			push_to_stack_a(stack_a, stack_b);
			stack_size_b = stack_size(*stack_b);
		}
		while (*stack_a != find_lowest_node(stack_a))
		{
			if (find_lowest_node(stack_a)->index > stack_size(*stack_a))
				rr_stack_a(stack_a);
			else
				rotate_stack_a(stack_a);
		}
	}
}
