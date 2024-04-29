/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:44 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/29 19:53:54 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief
 *
 * @param stack_source
 * @param dest_source
 * @param ind_a
 * @param ind_b
 * @return t_rotation*
 */

t_rotation	*rotate_cost(t_stack **stack_a, t_stack **stack_b, int ind_a,
		int ind_b)
{
	t_rotation	*nbr_rot;
	int			size_a;
	int			size_b;
	int			ra;
	int			rb;

	nbr_rot = malloc(sizeof(t_rotation));
	if (!nbr_rot)
		return (NULL);
	size_a = stack_size(*stack_a) - 1;
	size_b = stack_size(*stack_b) - 1;
	ra = ind_a;
	rb = ind_b;
	if (ra <= size_a - ra)
		nbr_rot->rot_a = ra;
	else
		nbr_rot->rot_a = ra - size_a - 1;
	if (rb <= size_b - rb)
		nbr_rot->rot_b = rb;
	else
		nbr_rot->rot_b = rb - size_b - 1;
	return (nbr_rot);
}
