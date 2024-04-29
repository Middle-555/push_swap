/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 18:00:23 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*index_a;
	int		index_b;


	index_a = *stack_a;
	while (index_a)
	{
		index_b = find_target_index(index_a, *stack_b);
		
		index_a = index_a->next;
	}

}
