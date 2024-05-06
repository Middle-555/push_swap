/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:29:32 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:19:43 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Sorts a stack with exactly two elements.
 * 
 * If the stack is not in order, it swaps the two elements to sort them.
 * 
 * @param stack Pointer to the stack of two elements.
 */

void	sort_2_entries(t_stack **stack)
{
	t_stack		*lowest;

	lowest = find_lowest_node(stack);
	if ((*stack) != lowest)
		swap_stack_a(stack);
	else
		return ;
}
