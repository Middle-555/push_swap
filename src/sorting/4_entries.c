/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:45:48 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:20:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sorts a stack with exactly four elements.
 * 
 * Moves one element to another stack, sorts the remaining three, then
 * integrates the moved element back into the sorted stack.
 * 
 * @param stack_a Main stack to sort.
 * @param stack_b Auxiliary stack used for temporary storage.
 */

void	sort_4_entries(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack_b(stack_a, stack_b);
	sort_3_entries(stack_a);
	while (*stack_b != NULL)
	{
		find_best_rotation(stack_a, stack_b);
		push_to_stack_a(stack_a, stack_b);
	}
	while (*stack_a != find_lowest_node(stack_a))
	{
		if (!(check_lst_sorted(stack_a)))
			rotate_stack_a(stack_a);
	}
}
