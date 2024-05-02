/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/02 22:02:15 by kpourcel         ###   ########.fr       */
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
	int			team_bs;

	current_a = *stack_a;
	index_a = 0;
	team_bs = 0;
	index_b = find_target_index(current_a, *stack_b);
	low_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
	while (current_a)
	{
		index_b = find_target_index(current_a, *stack_b);
		rot_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
		if (total_move(rot_cost) < total_move(low_cost))
		{
			ft_printf("enter low cost \n");
			low_cost = rot_cost;
			team_bs = index_b;
		}
		current_a = current_a->next;
		index_a++;
	}
	printf ("TARGET MON GARS : %d\n", team_bs);
	printf ("ROTATION MON GARS A : %d \n", low_cost.rot_a);
	printf ("ROTATION MY G  B: %d \n", low_cost.rot_b);
	printf(" CONTROLE DE low_cost : %d \n", total_move(low_cost));
	ft_printf("CECI EST UNE SEPARTION \n \n");
	exec_move(low_cost, stack_a, stack_b);
}
