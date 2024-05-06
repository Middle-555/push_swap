/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:47:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 17:54:17 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/libft/include/libft.h"
# include "push_swap.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// checker
// -> checker.c
int				main(int argc, char **argv);
// -> check.c
void			check_result(t_stack **stack_a);
int				instruction_check(t_stack **stack_a,
					t_stack **stack_b, char *str);
int				instruction_check_rotate(t_stack **stack_a,
					t_stack **stack_b, char *str);
int				get_instruction(t_stack **stack_a,
					t_stack **stack_b);

#endif