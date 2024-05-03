/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/03 15:25:35 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	sorting2(t_stack **stack_b, t_stack **stack_a)
{
	t_stack		*current_b;
	int			index_a;
	int			index_b;
	t_rotation	rot_cost;
	//t_rotation	low_cost;

	current_b = *stack_b;
	index_b = 0;
	index_a = find_target_in_stack_a(current_b, *stack_a);
	printf("Index_a : %d \n", index_a);
	//low_cost = rotate_cost(stack_b, stack_a, index_b, index_a);
	while (current_b)
	{
		index_a = find_target_in_stack_a(current_b, *stack_a);
		printf("Index_a : %d \n", index_a);
		rot_cost = rotate_cost(stack_b, stack_a, index_b, index_a);
		//if (total_move(low_cost) > total_move(rot_cost))
			//low_cost = rot_cost;
		current_b = current_b->next;
		index_b++;
	}
	exec_move(rot_cost, stack_b, stack_a);
}
