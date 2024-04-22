/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:07:38 by kpourcel          #+#    #+#             */
/*   Updated: 2024/04/22 15:43:13 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/ft_printf/include/ft_printf.h"
# include "../libraries/get_next_line/include/get_next_line.h"
# include "../libraries/libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

// error_handling

// -> error_utils.c
void				check_number(char **tab);
void				int_checker(char **tab);
void				check_double(char **tab);
long				ft_atol(const char *str);
void				check_duplicates(char **tab);
int					get_tab_size(char **tab);

// -> error.c
void				error_msg(char *str);
void				sign_checking(char **tab);
void				all_error_checking(char **tab);

// -> free.c
void				free_tab(char **tab);
void				free_linked_list(t_stack *lst);
void				free_both_stack(t_data *data);

// move

// -> push.c
void				push(t_stack **actual_stack, t_stack **dest_stack);
void				push_to_stack_a(t_stack **stack_a, t_stack **stack_b);
void				push_to_stack_b(t_stack **stack_a, t_stack **stack_b);

// -> reverse_rotate.c
void				reverse_rotate(t_stack **stack);
void				rr_stack_a(t_stack **stack_a);
void				rr_stack_b(t_stack **stack_b);
void				rr_both_stack(t_stack **stack_a, t_stack **stack_b);
// -> rotate.c
void				rotate(t_stack **stack);
void				rotate_stack_a(t_stack **stack_a);
void				rotate_stack_b(t_stack **stack_b);
void				rotate_both_stack(t_stack **stack_a, t_stack **stack_b);

// -> swap.c
void				swap(t_stack **stack);
void				swap_stack_a(t_stack **stack_a);
void				swap_stack_b(t_stack **stack_b);
void				swap_both_stack(t_stack **stack_a, t_stack **stack_b);

// sorting

// -> 2_entries.c
void				sort_2_entries(t_stack **stack_a);
// -> 3_entries.c
void				sort_3_entries(t_stack **stack_a);

// -> sorting_utils.c
t_stack				*find_highest_node(t_stack **stack);
t_stack				*find_lowest_node(t_stack **stack);
int					check_lst_sorted(t_stack **stack);

// -> sorting.c
void				entries_handler(t_stack **stack);

// utils

// -> utils.c
char				**init_tab(int argc, char **argv);
char				**add_tab(int argc, char **argv);
int					ft_strcmp(char *s1, char *s2);

// -> utils_linked_list.c
t_stack				*lst_new(t_stack *stack, int pos, int value);
void				fill_stack_a(char **tab, t_data *data);
t_stack				*lst_last(t_stack *lst);
void				init_stack(t_data *data);
int					lst_size(t_stack *lst);

// -> utils2_linked_list.c
t_stack				*creade_new_node(int value);
void				add_on_top(t_stack **stack, t_stack *new_node);

// -> test.c
void				print_tab(char **tab);
void				lst_print(t_stack *lst);

// main.c
#endif