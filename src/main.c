/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:16 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 11:12:43 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**tab;

	printf("Programme démarré\n");
	if (argc == 1)
	{
		error_msg("Usage: ./push_swap [tableau d'entiers]");
		return (1);
	}
	tab = init_tab(argc, argv);
	printf("Arguments analysés\n");
	all_error_checking(tab);
	printf("Vérification des erreurs terminée\n");
	init_stack(&data);
	printf("Piles initialisées\n");
	fill_stack_a(tab, &data);
	printf("Pile A remplie\n");
	// Création de quelques éléments dans la pile B pour les tests
	push_to_stack_b(&data.stack_a, &data.stack_b);
	push_to_stack_b(&data.stack_a, &data.stack_b);
	push_to_stack_b(&data.stack_a, &data.stack_b);
	printf("Pile B remplie\n");
	sorting(&data.stack_a, &data.stack_b);
	// Libération de la mémoire et fin du programme
	free_both_stack(&data);
	printf("Ressources libérées, programme terminé\n");
	return (0);
}
