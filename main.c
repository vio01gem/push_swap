/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:03 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/04 10:02:53 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int ac, char **av)
{
    char    **numbers;
    t_list  *stack_a;
    t_list  *stack_b;
    t_list  *clone;
    t_list  *head_a;              // Save head for reset. just a temp variable

    if (ac < 2)
        return (0);
    stack_b = NULL;
    numbers = parse_input(av);
    stack_a = build_stack(numbers);
    free_array(numbers);
    head_a = stack_a;               // Save head for reset
    clone = clone_stack(stack_a);   // Clone the stack
    sort_clone(clone);              // Sort clone and assign pos
    if_sorted(stack_a, clone);      // Exit if already sorted
    assign_pos(stack_a, clone);     // Transfer pos to original
    free_lst(clone);                // Free the clone
    stack_a = head_a;               // Reset stack_a to head
    sort_stack(&stack_a, &stack_b);
    free_lst(stack_a);               // Free the stack after sorting
    return (0);
}
