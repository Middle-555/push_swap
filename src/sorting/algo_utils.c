/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:54:35 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 22:04:19 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Searches for a given value in the stack and returns its index.
 *
 * This function iterates through the stack, starting from the head, to find the
 * first occurrence of a specified value. It returns the index of the element
 * where the value is found. If the value is not found, or if the stack is NULL,
 * the function returns -1.
 *
 * @param stack Pointer to the head of the stack. This must point to a valid and
 * initialized stack or be NULL.
 * @param value The integer value to search for in the stack.
 *
 * Operation:
 * - Checks if the stack pointer is NULL or points to an empty stack,
	immediately
 *   returning -1 if true.
 * - Iterates through each element of the stack, comparing the element's value
 *   to the target value.
 * - Returns the index of the first element that matches the target value. If no
 *   match is found by the end of the stack, returns -1.
 *
 * @return int The zero-based index of the first occurrence of the value, or -1
 * if the value is not found or the stack is NULL.
 */
/*
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

void	calculate_movement_cost(t_stack *stack, t_stack *target, int stack_size)
{
	int	target_index;
	int	ra_needed;
	int	rra_needed;

	if (!stack || !target)
		return ;
	while (stack)
	{
		if (stack->target)
		{
			target_index = find_index(&target, stack->target->value);
			ra_needed = target_index;
			rra_needed = stack_size - target_index;
			if (ra_needed < rra_needed)
			{
				stack->cost = ra_needed;
			}
			else
			{
				stack->cost = rra_needed;
			}
		}
		else
			stack->cost = -1;
		stack = stack->next;
	}
}

void	update_all_costs(t_stack **stack_a, t_stack **stack_b)
{
	int	size_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	size_b = stack_size(stack_b);
	calculate_movement_cost(*stack_a, *stack_b, size_b);
}
*/

// Trouve l'index d'une valeur spécifique dans la pile.
int	find_index(t_stack *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
		{
			return (index);
		}
		stack = stack->next;
		index++;
	}
	return (-1); // Retourne -1 si la valeur n'est pas trouvée.
}

// Calcule le coût pour amener un élément au sommet de la pile.
int	calculate_cost(int index, int stack_size)
{
	int ra_cost = index;              
		// Nombre de rotations nécessaires pour amener l'élément au sommet.
	int rra_cost = stack_size - index;
		// Nombre de rotations inverses nécessaires.
	if (ra_cost < rra_cost)
		return (ra_cost);
	else
		return (rra_cost);
}

// Met à jour le coût pour chaque élément dans la pile A basé sur la position de sa cible dans la pile B.
void	update_all_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	int		target_index;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	current_a = *stack_a;
	int stack_b_size = stack_size(stack_b);
		// Taille de la pile B pour le calcul des coûts.
	while (current_a)
	{
		if (current_a->target)
		{
			target_index = find_index(*stack_b, current_a->target->value);
			current_a->cost = calculate_cost(target_index, stack_b_size);
		}
		else
		{
			current_a->cost = -1;
				// Aucune cible n'a été trouvée ou est inappropriée.
		}
		current_a = current_a->next;
	}
}
