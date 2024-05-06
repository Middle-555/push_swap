/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:58:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 18:31:05 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tab;

	if (argc == 1)
	{
		error_msg("Usage: ./push_swap [tableau d'entiers]");
		return (1);
	}
	printf("main 1\n");
	tab = init_tab(argc, argv);
	printf("main 2\n");
	all_error_checking(tab);
	printf("main 3\n");
	init_stack(&data);
	printf("main 4\n");
	fill_stack_a(tab, &data);
	printf("main 5\n");
	if (check_lst_sorted(&data.stack_a) == 0)
		free_both_stack(&data);
	printf("main 6\n");
	else
	{
		get_instruction(&data.stack_a, &data.stack_b);
		check_result(&data.stack_a);
		free_both_stack(&data);
	}
	return (0);
}
