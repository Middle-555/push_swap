/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:35 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 18:06:01 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Searches for the given value in the stack and returns its index.
 * 
 * @param stack Pointer to the head of the stack.
 * @param value The integer value to find in the stack.
 * @return int The index of the first occurrence of the value in the stack,
 *             or -1 if the value is not found.
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
