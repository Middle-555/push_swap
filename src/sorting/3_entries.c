/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:28:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 15:16:28 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3_entries(t_stack **stack_a)
{
	t_stack	*highest;

	highest = find_highest_node(stack_a);
	if (*stack_a == highest)
		rotate_stack_a(stack_a);
	else if ((*stack_a)->next == highest)
		rr_stack_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_stack_a(stack_a);
}
