/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:38:25 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 18:55:45 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param stack 
 */

void	entries_handler(t_stack **stack_a, t_stack **stack_b)
{
	if (lst_size(*stack_a) == 2)
		sort_2_entries(stack_a);
	else if (lst_size(*stack_a) == 3)
		sort_3_entries(stack_a);
	else if (lst_size(*stack_a) > 3 )
		sort_3_entries(stack_a);
}
