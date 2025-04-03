/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:03:21 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/03 09:28:03 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a new t_list node with the given value
t_list  *create_node(int value)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        exit_with_error();
    new->value = value;
    new->pos = 0;
    new->next = NULL;
    return (new);
}

// Adds a new node to the back of the list
void    stack_add_back(t_list **stack, t_list *new)
{
    t_list  *temp;

    if (!*stack)
        *stack = new;
    else
    {
        temp = *stack;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

// Checks if a value already exists in the list
int     has_duplicate(t_list *stack, int value)
{
    t_list  *temp;

    temp = stack;
    while (temp)
    {
        if (temp->value == value)
            return (1);
        temp = temp->next;
    }
    return (0);
}

t_list  *build_stack(char **numbers)
{
    t_list  *stack;
    int     i;
    int     value;

    stack = NULL;
    i = 0;
    while (numbers[i])
    {
        if (!check_valid(numbers[i]))
            exit_with_error();
        value = (int)ft_atoi_bounds(numbers[i]);
        if (has_duplicate(stack, value))
            exit_with_error();
        stack_add_back(&stack, create_node(value));
        i++;
    }
    return (stack);
}
