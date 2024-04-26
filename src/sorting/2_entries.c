/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:29:32 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 14:47:31 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param stack 
 */

void	sort_2_entries(t_stack **stack)
{
	t_stack		*lowest;

	lowest = find_lowest_node(stack);
	if ((*stack) != lowest)
		swap_stack_a(stack);
	else
		return ;
}
