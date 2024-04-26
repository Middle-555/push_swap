/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 18:56:04 by kpourcel         ###   ########.fr       */
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
		start_push_b(&data.stack_a, &data.stack_b);
		free_both_stack(&data);
	}
}
