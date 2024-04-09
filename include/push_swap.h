/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/09 15:43:45 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_data;
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*target;
	int				index;
	int				value;
	int				cost;
}					t_stack;

// movement.c

#endif