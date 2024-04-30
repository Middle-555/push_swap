/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:55:29 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 23:37:06 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief
 *
 * @param src
 * @param dst
 * @return int
 */

int	find_target_index(t_stack *src, t_stack *dst)
{
	int		min_diff;
	int		diff;
	int		best_dst;

	min_diff = __INT_MAX__;
	best_dst = dst->index;

	if (src->value > find_highest_node(&dst)->value)
		return (find_highest_node(&dst)->index);
	else if (src->value < find_lowest_node(&dst)->value)
		return (find_highest_node(&dst)->index);
	while (dst)
	{
		diff = src->value - dst->value;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best_dst = dst->index;
		}
		dst = dst->next;
	}
	return (best_dst);
}
