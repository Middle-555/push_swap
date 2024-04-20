/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_entries.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:28:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/20 16:05:54 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3_entries(t_stack **stack)
{
	t_stack	*lowest;
	t_stack	*highest;

	lowest = find_lowest_node(stack);
	highest = find_highest_node(stack);
}
