/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/02 19:22:24 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tab;

	ft_printf("Programme démarré\n");
	if (argc == 1)
	{
		error_msg("Usage: ./push_swap [tableau d'entiers]");
		return (1);
	}
	tab = init_tab(argc, argv);
	ft_printf("Arguments analysés\n");
	all_error_checking(tab);
	ft_printf("Vérification des erreurs terminée\n");
	init_stack(&data);
	ft_printf("Piles initialisées\n");
	fill_stack_a(tab, &data);
	ft_printf("Pile A remplie\n");
	entries_handler(&data.stack_a, &data.stack_b);
	ft_printf("Pile B remplie\n");
	// Libération de la mémoire et fin du programme
	free_both_stack(&data);
	ft_printf("Ressources libérées, programme terminé\n");
	return (0);
}
