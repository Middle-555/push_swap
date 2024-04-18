/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/18 19:01:53 by kpourcel         ###   ########.fr       */
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
		ft_printf("\nSize  : %d\n", lst_size(data.stack_a));
	}
}
