/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:58:54 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/18 19:34:56 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	second_to_last = NULL;
	if (!(*stack) || !(*stack)->next)
		return ;
	last = lst_last(*stack);
	second_to_last = *stack;
	while (second_to_last ->next != last)
	{
		second_to_last = second_to_last->next;
	}
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rr_stack_a(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
	return ;
}

void	rr_stack_b(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return ;
}

void	rr_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return ;
}
