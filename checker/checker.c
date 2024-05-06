/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:58:14 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 21:53:13 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tab;

	if (argc == 1)
	{
		error_msg("Write the same arg than ./push_swap");
		return (1);
	}
	tab = init_tab(argc, argv);
	all_error_checking(tab);
	init_stack(&data);
	fill_stack_a(tab, &data);
	if (check_lst_sorted(&data.stack_a) == 0)
		free_both_stack(&data);
	else
	{
		get_instruction(&data.stack_a, &data.stack_b);
		check_result(&data.stack_a);
		free_both_stack(&data);
	}
	return (0);
}
