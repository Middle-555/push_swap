/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:04:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/30 14:55:48 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	absolute_val(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

int	absolute_min(int a, int b)
{
	if (absolute_val(a) < absolute_val(b))
		return (a);
	else
		return (b);

}

int	absolute_max(int a, int b)
{
	if (absolute_val(a) > absolute_val(b))
		return (absolute_val(a));
	else
		return (absolute_val(b));
}

