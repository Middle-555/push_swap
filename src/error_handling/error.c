/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:34:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/15 19:32:29 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error_msg(char *str)
{
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit(0);
}

void	all_error_checking(char **tab)
{
	check_number(tab);
	int_checker(tab);
}

zzzea
