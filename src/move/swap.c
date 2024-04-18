/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:57:19 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/18 14:33:34 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first_element;
	int		stock_value;

	if (!*stack)
		return (NULL);
	first_element = stack;
	stock_value = first_element->value;
	first_element->value = first_element->next->value;
	first_element->next->value = stock_value;
	return ;
}
