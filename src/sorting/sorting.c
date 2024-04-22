/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:38:25 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 15:44:46 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	entries_handler(t_stack **stack)
{
	if (lst_size(*stack) == 2)
		sort_2_entries(stack);
	else if (lst_size(*stack) == 3)
		sort_3_entries(stack);
}
