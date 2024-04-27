/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 17:33:44 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void print_stack_and_targets(t_stack *stack) 
{
    while (stack) 
    {
        int target_value = stack->target ? stack->target->value : -1;  // -1 si pas de cible
        printf("Value: %d, Target: %d\n", stack->value, target_value);
        stack = stack->next;
    }
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tab;

	if (argc == 1)
		error_msg("./push_swap [array of int]");
	else
	{
		tab = init_tab(argc, argv);
		all_error_checking(tab);
		init_stack(&data);
		fill_stack_a(tab, &data);
		if (check_lst_sorted(&data.stack_a) == 1)
		{
			entries_handler(&data.stack_a);
		}
		start_push_b(&data.stack_a, &data.stack_b);
		start_push_b(&data.stack_a, &data.stack_b);
		push_to_stack_b(&data.stack_a, &data.stack_b);
		ft_printf("Stack A :\n");
		lst_print(data.stack_a);
		ft_printf("Stack B :\n");
		lst_print(data.stack_b);
		find_target(&data.stack_a, &data.stack_b);
		ft_printf("Stack A with targets from Stack B:\n");
		print_stack_and_targets(data.stack_a);
		free_both_stack(&data);
	}
}
