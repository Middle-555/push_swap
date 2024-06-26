/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:28:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:19:52 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sorts a stack with exactly three elements.
 * 
 * Arranges three elements in ascending order using a combination of rotates
 * and swaps as necessary.
 * 
 * @param stack_a Pointer to the stack of three elements.
 */

void	sort_3_entries(t_stack **stack_a)
{
	t_stack	*highest;

	highest = find_highest_node(*stack_a);
	if (*stack_a == highest)
		rotate_stack_a(stack_a);
	else if ((*stack_a)->next == highest)
		rr_stack_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_stack_a(stack_a);
}
