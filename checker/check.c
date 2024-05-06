/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:58:01 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 18:31:14 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	check_result(t_stack **stack_a)
{
	if (check_lst_sorted(stack_a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	get_instruction(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	printf("0\n");
	while (instruction && instruction[0] != '\n')
	{
		printf("printavant le if \n");
		if (instruction_check(stack_a, stack_b, instruction))
		{
			printf("1\n");
			free(instruction);
			printf("2\n");
			ft_printf("Error\n");
			printf("3\n");
			return (-1);
		}
		printf("print entre le if \n");
		if (check_lst_sorted(stack_a) == (-1) && stack_b == NULL)
		{
			printf("4\n");
			free(instruction);
			printf("5\n");
			return (0);
		}
		printf("6\n");
		free(instruction);
		printf("7\n");
		instruction = get_next_line(0);
		printf("8\n");
	}
	printf("9\n");
	free(instruction);
	printf("10\n");
	return (0);
}

int	instruction_check(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		push(stack_a, stack_b);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(stack_b, stack_a);
	else if (ft_strcmp(str, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(stack_b);
	else if ((ft_strcmp(str, "ss\n") == 0))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (instruction_check_rotate(stack_a, stack_b, str) == -1)
		return (-1);
	return (0);
}

int	instruction_check_rotate(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rr\n") == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(str, "rrr\n") == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
	else
		return (-1);
	return (0);
}
