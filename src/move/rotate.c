/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:57:15 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/18 19:00:08 by kpourcel         ###   ########.fr       */
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
