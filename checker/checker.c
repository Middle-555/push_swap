/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:26:09 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 15:28:28 by kpourcel         ###   ########.fr       */
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
	tab = init_tab(argc, argv);
	all_error_checking(tab);
	init_stack(&data);
	fill_stack_a(tab, &data);
	if (check_lst_sorted(&data.stack_a) == 0)
		free_both_stack(&data);
	else
	{
		//check
		free_both_stack(&data);
	}
	return (0);
}
