/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:38:25 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 16:06:51 by kpourcel         ###   ########.fr       */
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
	int	stack_size_a;

	(void)stack_b;
	stack_size_a = lst_size(*stack_a);
	if (stack_size_a == 2)
		sort_2_entries(stack_a);
	else if (stack_size_a == 3)
		sort_3_entries(stack_a);
	else if (stack_size_a > 3)
	{
		while (lst_size(*stack_a) > 3)
		{
		}
		sort_3_entries(stack_a);
	}
}
