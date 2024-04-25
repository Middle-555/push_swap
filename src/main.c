/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/25 14:55:01 by kpourcel         ###   ########.fr       */
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
		if (check_lst_sorted(&data.stack_a) == 1)
		{
			entries_handler(&data.stack_a);
		}
		lst_print(data.stack_a);
		free_both_stack(&data);
	}
}
