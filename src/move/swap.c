/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:57:19 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/18 14:49:32 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief This function is a swap of value between our first element 
 * and our next element.
 * @param stack We choose on which stack we want to apply this swap.
 * it can be stack_a, stack_b or both.
 */
void	swap(t_stack **stack)
{
	t_stack	*first_element;
	int		stock_value;

	if (!*stack)
		return ;
	first_element = *stack;
	stock_value = first_element->value;
	first_element->value = first_element->next->value;
	first_element->next->value = stock_value;
	return ;
}

void	swap_stack_a(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
	return ;
}

void	swap_stack_b(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
	return ;
}

void	swap_both_stack(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap (stack_b);
	ft_printf("ss\n");
	return ;
}
