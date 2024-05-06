/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:38:25 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:42:35 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Handles sorting of stacks based on their size.
 * 
 * Depending on the number of elements, it delegates the sorting task to the 
 * appropriate function to manage stacks of 2 to 5+ elements.
 *
 * @param stack_a Main stack to be sorted.
 * @param stack_b Auxiliary stack for operations.
 */

void	entries_handler(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size_a;

	stack_size_a = stack_size(*stack_a);
	if (stack_size_a == 2)
		sort_2_entries(stack_a);
	else if (stack_size_a == 3)
		sort_3_entries(stack_a);
	else if (stack_size_a == 4)
		sort_4_entries(stack_a, stack_b);
	else if (stack_size_a == 5)
		sort_5_entries(stack_a, stack_b);
	else if (stack_size_a > 5)
		sort_large_stack(stack_a, stack_b);
}
