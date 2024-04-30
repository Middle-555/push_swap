/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:10:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 15:08:24 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
 * Check if we store correctly our input.
 */
void	print_tab(char **tab)
{
	int	w;

	w = 0;
	while (tab[w])
	{
		ft_printf("New word :");
		ft_printf("%s\n", tab[w]);
		w++;
	}
}

/**
 * @brief Used to print the value of each node during my test.
 * @param lst
 */
void	lst_print(t_stack *lst)
{
	while (lst != NULL)
	{
		ft_printf("value : %d\n", lst->value);
		lst = lst->next;
	}
}

/**
 * @brief Prints each element's value and its target's value in the stack.
 *        If no target is set, prints -1 for the target value.
 *
 * @param stack Pointer to the top of the stack.
 */
void	print_stack_and_targets(t_stack *stack)
{
	int	target_value;

	while (stack)
	{
		target_value = -1;
		if (stack->target != NULL)
		{
			target_value = stack->target->value;
		}
		ft_printf("Value: %d, Target: %d\n", stack->value, target_value);
		stack = stack->next;
	}
}

// Function to print the cost details for each element in the stack
void	print_stack_costs(t_stack *stack)
{
	int	index;

	index = 0;
	ft_printf("Cost details for each element in the stack:\n");
	while (stack != NULL)
	{
		ft_printf("Element %d: value = %d, cost = %d\n", index, stack->value,
			stack->cost);
		stack = stack->next;
		index++;
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("Stack A\t\tStack B\n");
	ft_printf("-------\t\t-------\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
			ft_printf("%d [%d]\t", stack_a->value, stack_a->index);
		else
			ft_printf("\t\t");

		if (stack_b != NULL)
			ft_printf("%d [%d]\n", stack_b->value, stack_b->index);
		else
			ft_printf("\n");

		if (stack_a != NULL)
			stack_a = stack_a->next;
		if (stack_b != NULL)
			stack_b = stack_b->next;
	}
}
