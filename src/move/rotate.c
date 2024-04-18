/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:57:15 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/18 19:05:39 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*first_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = lst_last(*stack);
	first_node = *stack;
	*stack = (*stack)-> next;
	first_node->next = NULL;
	last_node->next = first_node;
}

void	rotate_stack_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
	return ;
}

void	rotate_stack_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("ra\n");
	return ;
}

void	rotate_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	return ;
}
