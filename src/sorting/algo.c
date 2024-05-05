/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:08:56 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/05 17:19:39 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_4_entries(t_stack **stack_a, t_stack **stack_b)
{
	push_to_stack_b(stack_a, stack_b);
	sort_3_entries(stack_a);
	while (*stack_b != NULL)
	{
		find_best_rotation(stack_a, stack_b);
		push_to_stack_a(stack_a, stack_b);
	}
	while (*stack_a != find_lowest_node(stack_a))
	{
		if (!(check_lst_sorted(stack_a)))
			rotate_stack_a(stack_a);
	}
}
/*
void sort_5_entries(t_stack **stack_a, t_stack **stack_b) 
{
    // Pousser deux éléments vers stack_b, en supposant que stack_b est vide initialement.
       if (is_rev_sorted(*stack_a))
        cinq_s_t(stack_a, stack_b);
    push_to_stack_b(stack_a, stack_b);
    push_to_stack_b(stack_a, stack_b);

    // Tri de trois éléments dans stack_a.
    sort_3_entries(stack_a);

    // Traiter chaque élément dans stack_b.
    while (*stack_b != NULL) {
        find_best_rotation(stack_a, stack_b);
        push_to_stack_a(stack_a, stack_b);// Assurez-vous que les trois premiers éléments de stack_a sont toujours triés après chaque push.
    }

    // Ajuster stack_a pour s'assurer que le plus petit élément est au début.
    while (*stack_a != find_lowest_node(stack_a)) {
        rotate_stack_a(stack_a);  // Vous pourriez avoir besoin de rr_stack_a si c'est dans le sens inverse.
    }
}
*/
void sort_5_entries(t_stack **stack_a, t_stack **stack_b)
{

    t_stack    *smallest_node;
    int        size;

    if (reverse_sorted(*stack_a))
         Opti_5(stack_a, stack_b);
    else
    {
        size = stack_size(*stack_a);
        while (stack_size(*stack_a) > 3)
        {
            smallest_node = find_lowest_node(stack_a);
            while (*stack_a != smallest_node)
                rotate_stack_a(stack_a);
          push_to_stack_b(stack_a, stack_b);;
        }
        sort_3_entries(stack_a);
        if (size == 5)
        {
            smallest_node = find_lowest_node(stack_b);
            if (*stack_b == smallest_node)
                swap_stack_b(stack_b);
           push_to_stack_a(stack_a, stack_b);
        }
      push_to_stack_a(stack_a, stack_b);
    }
}


void   Opti_5(t_stack **stack_a, t_stack **stack_b)
{
    rr_stack_a(stack_a);
    push_to_stack_b(stack_a, stack_b);
    swap_stack_a(stack_a);
    rotate_stack_a(stack_a);
    rotate_stack_a(stack_a);
    swap_stack_a(stack_a);
    push_to_stack_a(stack_a, stack_b);
}

int    reverse_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value < stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void	sorting(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*current_a;
	int			index_a;
	int			index_b;
	t_rotation	rot_cost;
	t_rotation	low_cost;

	current_a = *stack_a;
	index_a = 0;
	index_b = find_target_index(current_a, *stack_b);
	low_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
	while (current_a)
	{
		index_b = find_target_index(current_a, *stack_b);
		rot_cost = rotate_cost(stack_a, stack_b, index_a, index_b);
		if (total_move(low_cost) > total_move(rot_cost))
			low_cost = rot_cost;
		current_a = current_a->next;
		index_a++;
	}
	exec_move(low_cost, stack_a, stack_b);
}

