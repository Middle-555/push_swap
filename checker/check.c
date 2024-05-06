/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:26:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 15:42:41 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	check_result(t_stack **stack_a)
{
	if (check_lst_sorted == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	get_instruction(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction && instruction[0] != "\n")
	{
		if (instruction_check(stack_a, stack_b, *instruction))
		{
			free(instruction);
			ft_prinf("Error\n");
			return (-1);
		}
		if (check_lst_sorted(stack_a) == (-1))
		{
			free(instruction);
			return (0);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
}

int	instruction_check(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push_to_stack_a(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push_to_stack_b(stack_a, stack_b);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap_stack_a(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_stack_b(stack_b);
	else if ((ft_strcmp(str, "ss\n") == 0))
		swap_both_stack(stack_a, stack_b);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate_stack_a(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate_stack_b(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_both_stack(stack_a, stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		rr_stack_a(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rr_stack_b(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rr_both_stack(stack_a, stack_b);
	else
		return (-1);
	return (0);
}
