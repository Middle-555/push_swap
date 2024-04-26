/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:00:45 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/26 14:50:20 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief 
 * 
 * @param str 
 * @return long 
 */

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && 13 >= *str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && '9' >= *str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

/**
 * @brief 
 * 
 * @param tab 
 */

void	int_checker(char **tab)
{
	int		i;
	long	nbr;

	i = 0;
	while (tab[i])
	{
		nbr = ft_atol(tab[i]);
		if (nbr <= INT_MIN || nbr >= INT_MAX)
		{
			free_tab(tab);
			error_msg("The value need to be an INT");
		}
		i++;
	}
}

/**
 * @brief Get the tab size object
 * 
 * @param tab 
 * @return int 
 */

int	get_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

/**
 * @brief 
 * 
 * @param tab 
 */

void	check_duplicates(char **tab)
{
	int	i;
	int	j;
	int	size;

	size = get_tab_size(tab);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_atol(tab[i]) == ft_atol(tab[j]))
			{
				free_tab(tab);
				error_msg("Error : Double are not allowed\n");
			}
			j++;
		}
		i++;
	}
}
