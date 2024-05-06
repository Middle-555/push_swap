/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:44 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:44:49 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Calculates the least costly rotation to align two stacks.
 * 
 * Determines the optimal rotation strategy for aligning elements between two
 * stacks, minimizing the total rotation cost.
 *
 * @param stack_a Source stack.
 * @param stack_b Destination stack.
 * @param ind_a Index in stack_a for rotation.
 * @param ind_b Index in stack_b for rotation.
 * @return t_rotation Structure with rotation details for both stacks.
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

/**
 * @brief Computes the total movement cost for a rotation operation.
 * 
 * Calculates the overall movement cost by considering both rotations and
 * their directions to determine the most efficient total movement.
 *
 * @param nbr_rot Rotation details containing the individual rotations.
 * @return int The total cost of executing the rotations.
 */

int	total_move(t_rotation nbr_rot)
{
	if (nbr_rot.rot_a > 0 && nbr_rot.rot_b > 0)
		return (max(nbr_rot.rot_a, nbr_rot.rot_b));
	else if (nbr_rot.rot_a < 0 && nbr_rot.rot_b < 0)
		return (absolute_max(nbr_rot.rot_a, nbr_rot.rot_b));
	else
		return (absolute_val(nbr_rot.rot_a) + absolute_val(nbr_rot.rot_b));
}

/**
 * @brief Executes positive rotation movements on both stacks.
 * 
 * Performs simultaneous positive rotations on both stacks until all required
 * positive rotations are completed.
 *
 * @param nbr_rot Rotation details for the positive numbers.
 * @param stack_a Primary stack for execution.
 * @param stack_b Secondary stack for execution.
 */

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

/**
 * @brief Executes negative rotation movements on both stacks.
 * 
 * Performs simultaneous negative rotations on both stacks until all required
 * negative rotations are completed.
 *
 * @param nbr_rot Rotation details for the negative numbers.
 * @param stack_a Primary stack for execution.
 * @param stack_b Secondary stack for execution.
 */

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

/**
 * @brief Executes the movement based on calculated rotations.
 * 
 * Directs the execution of movements based on whether the rotation values are
 * positive or negative, ensuring both stacks are aligned optimally.
 *
 * @param nbr_rot Rotation details containing positive and negative rotations.
 * @param stack_a Primary stack for execution.
 * @param stack_b Secondary stack for execution.
 */

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
