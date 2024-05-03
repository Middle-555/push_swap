/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:38:25 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/03 11:59:29 by kpourcel         ###   ########.fr       */
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

	(void)stack_b;
	stack_size_a = stack_size(*stack_a);
	if (stack_size_a == 2)
		sort_2_entries(stack_a);
	else if (stack_size_a == 3)
		sort_3_entries(stack_a);
	else if (stack_size_a == 4)
	{
		push_to_stack_b(stack_a, stack_b);      
		sort_3_entries(stack_a);
	}
	else if (stack_size_a >= 5)
	{
		push_to_stack_b(stack_a, stack_b);
		push_to_stack_b(stack_a, stack_b);
		stack_size_a = stack_size(*stack_a);
		while (stack_size_a > 3)
		{
			sorting(stack_a, stack_b);
			push_to_stack_b(stack_a, stack_b);
			stack_size_a = stack_size(*stack_a);
		}
		sort_3_entries(stack_a);
		while (stack_size(*stack_b) > 0)
			push_to_stack_a(stack_a, stack_b);
		while (*stack_a != find_lowest_node(stack_a))
			rotate_stack_a(stack_a);
	}
}
