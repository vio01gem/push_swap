/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:03 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/02 15:30:40 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int ac, char **av)
{
    char    **numbers;
    t_list  *stack;
    // t_list  *temp;

    if (ac < 2)
        return (0);
    numbers = parse_input(av);
    stack = build_stack(numbers);
    free_array(numbers);
    // temp = stack;
    // while (temp)
    // {
    //     print_string("Value: ");
    //     print_string(ft_itoa(temp->value));
    //     print_string("\n");
    //     temp = temp->next;
    // }
    free_all(stack);
    return (0);
}
