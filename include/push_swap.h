/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/16 13:29:22 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/libft/include/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	int				index;
	int				value;
	int				cost;
}					t_stack;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_data;

//error_handling

// -> error_utils.c
void	check_number(char **tab);
void	int_checker(char **tab);
void	check_double(char **tab);
long	ft_atol(const char *str);
void	check_duplicates(char **tab);
int		get_tab_size(char **tab);

// -> error.c
void	error_msg(char *str);
void	sign_checking(char **tab);
void	all_error_checking(char **tab);

// -> free.c
void	free_tab(char **tab);

//move

// -> movement.c

//utils

// -> utils.c
char	**init_tab(int argc, char **argv);
char	**add_tab(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);
// -> test.c
void	print_tab(char **tab);

// main.c
#endif