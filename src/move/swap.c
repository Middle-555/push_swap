/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:57:19 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 11:44:57 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief This function is a swap of value between our first node 
 * and our next node.
 * @param stack We choose on which stack we want to apply this swap.
 * it can be stack_a, stack_b or both.
 */

void	swap(t_stack **stack)
{
	t_stack	*first_node;
	int		stock_value;

	if (!(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	stock_value = first_node->value;
	first_node->value = first_node->next->value;
	first_node->next->value = stock_value;
	return ;
}

/**
 * @brief 
 * 
 * @param stack_a 
 */

void	swap_stack_a(t_stack **stack_a)
{
	swap(stack_a);
	recalculate_index(*stack_a);
	ft_printf("sa\n");
	return ;
}

/**
 * @brief 
 * 
 * @param stack_b 
 */

void	swap_stack_b(t_stack **stack_b)
{
	swap(stack_b);
	recalculate_index(*stack_b);
	ft_printf("sb\n");
	return ;
}

/**
 * @brief 
 * 
 * @param stack_a 
 * @param stack_b 
 */

void	swap_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap (stack_b);
	recalculate_index(*stack_a);
	recalculate_index(*stack_b);
	ft_printf("ss\n");
	return ;
}
