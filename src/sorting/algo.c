/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/04 09:59:09 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	sort_5_entries(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack_b(stack_a, stack_b);
	push_to_stack_b(stack_a, stack_b);
	sort_3_entries(stack_a);
	while (*stack_b != NULL)
	{
		find_best_rotation(stack_a, stack_b);
		push_to_stack_a(stack_a, stack_b);
		find_best_rotation(stack_a, stack_b);
		push_to_stack_a(stack_a, stack_b);

	}
	while (*stack_a != find_lowest_node(stack_a))
	{
		if (!(check_lst_sorted(stack_a)))
			rotate_stack_a(stack_a);
	}
	print_stacks(*stack_a, *stack_b);
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
