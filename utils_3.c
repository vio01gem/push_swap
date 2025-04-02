/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:03:21 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/02 19:45:35 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a new t_list node with the given value
t_list  *create_node(int value)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        terminate_with_error();
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

// Adds numbers from a space-separated string to the stack
int     add_to_stack(t_list **stack, char *arg)
{
    char    **numbers;
    int     i;
    long    num;

    numbers = ft_split(arg, ' ');
    if (!numbers || !numbers[0])
        return (free_array(numbers), 0);
    i = 0;
    while (numbers[i])
    {
        if (!check_valid(numbers[i]))
            return (free_array(numbers), 0);
        num = ft_atoi_bounds(numbers[i]);
        if (has_duplicate(*stack, (int)num))
            return (free_array(numbers), 0);
        stack_add_back(stack, create_node((int)num));
        i++;
    }
    free_array(numbers);
    return (1);
}

// Initializes the stack from command-line arguments
void    init_stack(t_list **stack, char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        if (is_empty(av[i]) || !add_to_stack(stack, av[i]))
        {
            free_all(*stack);
            terminate_with_error();
        }
        i++;
    }
}

// Clones the stack for sorting
t_list  *clone_stack(t_list *stack)
{
    t_list  *clone;
    t_list  *new;

    clone = NULL;
    while (stack)
    {
        new = create_node(stack->value);
        stack_add_back(&clone, new);
        stack = stack->next;
    }
    return (clone);
}

// Sorts the stack and assigns pos based on sorted order
void    sort_positions(t_list *stack)
{
    t_list  *current;
    t_list  *next;
    int     pos;

    current = stack;
    while (current && current->next)
    {
        next = current->next;
        while (next)
        {
            if (current->value > next->value)
            {
                current->value ^= next->value;
                next->value ^= current->value;
                current->value ^= next->value;
            }
            next = next->next;
        }
        current = current->next;
    }
    current = stack;
    pos = 0;
    while (current)
    {
        current->pos = pos++;
        current = current->next;
    }
}
