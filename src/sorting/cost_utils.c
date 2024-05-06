/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:04:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 12:46:37 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief Returns the maximum of two integers.
 * 
 * Compares two integers and returns the larger of the two.
 *
 * @param a First integer to compare.
 * @param b Second integer to compare.
 * @return int The maximum value between a and b.
 */

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/**
 * @brief Returns the minimum of two integers.
 * 
 * Compares two integers and returns the smaller of the two.
 *
 * @param a First integer to compare.
 * @param b Second integer to compare.
 * @return int The minimum value between a and b.
 */

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

/**
 * @brief Calculates the absolute value of an integer.
 * 
 * Returns the non-negative magnitude of an integer.
 *
 * @param n The integer to evaluate.
 * @return int The absolute value of n.
 */

int	absolute_val(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

/**
 * @brief Returns the smaller of two integers based on their absolute values.
 * 
 * Compares the absolute values of two integers and returns the integer whose
 * absolute value is smaller.
 *
 * @param a First integer to compare.
 * @param b Second integer to compare.
 * @return int The integer with the smaller absolute value.
 */

int	absolute_min(int a, int b)
{
	if (absolute_val(a) < absolute_val(b))
		return (a);
	else
		return (b);
}

/**
 * @brief Returns the larger of two integers based on their absolute values.
 * 
 * Compares the absolute values of two integers and returns the integer whose
 * absolute value is larger.
 *
 * @param a First integer to compare.
 * @param b Second integer to compare.
 * @return int The integer with the larger absolute value.
 */

int	absolute_max(int a, int b)
{
	if (absolute_val(a) > absolute_val(b))
		return (absolute_val(a));
	else
		return (absolute_val(b));
}
