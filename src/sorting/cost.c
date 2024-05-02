/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:44 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/02 23:30:14 by kpourcel         ###   ########.fr       */
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

t_rotation	rotate_cost(t_stack **stack_a, t_stack **stack_b, int ind_a,
		int ind_b)
{
	t_rotation	nbr_rot;
	int			nb_move;
	int			rra;
	int			rrb;

	rra = -((stack_size(*stack_a) - ind_a));
	rrb = -((stack_size(*stack_b) - ind_b));
	nbr_rot.rot_a = absolute_min(ind_a, rra);
	nbr_rot.rot_b = absolute_min(ind_b, rrb);
	nb_move = total_move(nbr_rot);
	if (nb_move > max(ind_a, ind_b))
	{
		nb_move = max(ind_a, ind_b);
		nbr_rot.rot_a = ind_a;
		nbr_rot.rot_b = ind_b;
	}
	else if (nb_move > absolute_max(rra, rrb))
	{
		nb_move = absolute_max(rra, rrb);
		nbr_rot.rot_a = rra;
		nbr_rot.rot_b = rrb;
	}
	return (nbr_rot);
}

int	total_move(t_rotation nbr_rot)
{
	if (nbr_rot.rot_a > 0 && nbr_rot.rot_b > 0)
		return (max(nbr_rot.rot_a, nbr_rot.rot_b));
	else if (nbr_rot.rot_a < 0 && nbr_rot.rot_b < 0)
		return (absolute_max(nbr_rot.rot_a, nbr_rot.rot_b));
	else
		return (absolute_val(nbr_rot.rot_a) + absolute_val(nbr_rot.rot_b));
}

void	exec_positive_number(t_rotation nbr_rot, t_stack **stack_a,
		t_stack **stack_b)
{
	while (nbr_rot.rot_a > 0 && nbr_rot.rot_b > 0)
	{
		rotate_both_stack(stack_a, stack_b);
		nbr_rot.rot_a--;
		nbr_rot.rot_b--;
	}
	if (nbr_rot.rot_a > 0)
	{
		while (nbr_rot.rot_a > 0)
		{
			rotate_stack_a(stack_a);
			nbr_rot.rot_a--;
		}
	}
	else if (nbr_rot.rot_b > 0)
	{
		while (nbr_rot.rot_b > 0)
		{
			rotate_stack_b(stack_b);
			nbr_rot.rot_b--;
		}
	}
}

void	exec_negative_number(t_rotation nbr_rot, t_stack **stack_a,
		t_stack **stack_b)
{
	while (nbr_rot.rot_a < 0 && nbr_rot.rot_b < 0)
	{
		rr_both_stack(stack_a, stack_b);
		nbr_rot.rot_a++;
		nbr_rot.rot_b++;
	}
	if (nbr_rot.rot_a < 0)
	{
		while (nbr_rot.rot_a < 0)
		{
			rr_stack_a(stack_a);
			nbr_rot.rot_a++;
		}
	}
	else if (nbr_rot.rot_b < 0)
	{
		while (nbr_rot.rot_b < 0)
		{
			rr_stack_b(stack_b);
			nbr_rot.rot_b++;
		}
	}
}

void	exec_move(t_rotation nbr_rot, t_stack **stack_a, t_stack **stack_b)
{
	if (nbr_rot.rot_a > 0 && nbr_rot.rot_b > 0)
		exec_positive_number(nbr_rot, stack_a, stack_b);
	else if (nbr_rot.rot_a < 0 && nbr_rot.rot_b < 0)
		exec_negative_number(nbr_rot, stack_a, stack_b);
	else
	{
		exec_positive_number(nbr_rot, stack_a, stack_b);
		exec_negative_number(nbr_rot, stack_a, stack_b);
	}
}
