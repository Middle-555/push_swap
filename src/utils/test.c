/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:10:22 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 19:57:35 by kpourcel         ###   ########.fr       */
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
	while (stack)
	{
		printf("Value: %d, Target: %d\n", stack->value,
			stack->target ? stack->target->value : -1);
		stack = stack->next;
	}
}

/**
 * @brief Print the stack and associated costs for debugging and verification.
 *
 * @param stack Pointer to the top of the stack.
 */
void	print_stack_cost(t_stack *stack)
{
	while (stack)
	{
		ft_printf("Value: %d, Cost: %d\n", stack->value, stack->cost);
		stack = stack->next;
	}
}
