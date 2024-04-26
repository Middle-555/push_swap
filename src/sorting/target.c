/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 16:56:47 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	find_target_in_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		find_target_for_node(current_a, *stack_b);
		current_a = current_a->next;
	}
}
