/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:35 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 17:14:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param stack 
 * @param value 
 * @return int 
 */

int	find_index(t_stack **stack, int value)
{
	t_stack	*temp;
	int		i;

	if (!stack || !(*stack))
		return (-1);
	temp = *stack;
	i = 0;
	while (temp)
	{
		if (temp->value == value)
			return (i);
		i++;
		temp = temp->next;
	}
	return (-1);
}
