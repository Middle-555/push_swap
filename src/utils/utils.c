/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:13:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/12 19:06:50 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	**add_tab(int argc, char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * argc);
	if (!tab)
		return (NULL);
	while (i < argc - 1)
	{
		tab[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**init_tab(int argc, char **argv)
{
	char	**tab;

	if (argc == 2)
		tab = ft_split(argv[1], 32);
	else
		tab = add_tab(argc, argv);
	return (tab);
}
