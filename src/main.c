/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 15:35:13 by kpourcel         ###   ########.fr       */
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
		print_tab(tab);
		all_error_checking(tab);
		init_stack(&data);
		fill_stack_a(tab, &data);
		lst_print(data.stack_a);
		ft_printf("before sort \n");
		if (lst_size(data.stack_a) == 2)
		{
			sort_2_entries(&data.stack_a);
			ft_printf("test");
			lst_print(data.stack_a);
		}
		if (lst_size(data.stack_a) == 3)
		{
			ft_printf("\n Test 3 entries: \n");
			sort_3_entries(&data.stack_a);
			lst_print(data.stack_a);
		}
		ft_printf("done.");
		free_both_stack(&data);
	}
}
