/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/27 22:04:09 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
		push_to_stack_b(&data.stack_a, &data.stack_b);
		push_to_stack_b(&data.stack_a, &data.stack_b);
		push_to_stack_b(&data.stack_a, &data.stack_b);
		push_to_stack_b(&data.stack_a, &data.stack_b);
		push_to_stack_b(&data.stack_a, &data.stack_b);
		ft_printf("Stack A :\n");
		lst_print(data.stack_a);
		ft_printf("Stack B :\n");
		lst_print(data.stack_b);
		find_target(&data.stack_a, &data.stack_b);
		ft_printf("Stack A with targets from Stack B:\n");
		print_stack_and_targets(data.stack_a);
		update_all_costs(&data.stack_a, &data.stack_b);
		print_stack_cost(data.stack_a);
		free_both_stack(&data);
	}
}
