/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/05 17:47:57 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size_a;
	int	stack_size_b;

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
	final_adjustment(stack_a);
}

void	final_adjustment(t_stack **stack_a)
{
	while (*stack_a != find_lowest_node(stack_a))
	{
		if (find_lowest_node(stack_a)->index > (stack_size(*stack_a) / 2))
			rr_stack_a(stack_a);
		else
			rotate_stack_a(stack_a);
	}
}


void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current_a;
	int			index_a;
	int			index_b;
	t_rotation	rot_cost;
	t_rotation	low_cost;

	current_a = *stack_a;
	index_a = 0;
	index_b = find_target_index(current_a, *stack_b);
	low_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
	while (current_a)
	{
		index_b = find_target_index(current_a, *stack_b);
		rot_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
		if (total_move(low_cost) > total_move(rot_cost))
			low_cost = rot_cost;
		current_a = current_a->next;
		index_a++;
	}
	exec_move(low_cost, stack_a, stack_b);
}
