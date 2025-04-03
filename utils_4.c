/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:58:18 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/03 20:01:58 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Creates a duplicate of the stack
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

// Sorts the stack by value and assigns pos based on sorted order
void    sort_clone(t_list *stack)
{
    t_list  *head;
    t_list  *current;
    int     temp;
    
    if (!stack)
        exit_with_error(stack, NULL);
    head = stack;
    while (stack->next)
    {
        current = stack->next;
        while (current)
        {
            if (stack->value > current->value)
            {
                temp = stack->value;
                stack->value = current->value;
                current->value = temp;
            }
            current = current->next;
        }
        stack = stack->next;
    }
    index_cloner(head);
}

// Transfers pos from sorted clone to original stack
void  	assign_pos(t_list *stack_a, t_list *clone)
{
    t_list  *temp;

    temp = stack_a;
    while (clone)
    {
        while (stack_a)
        {
            if (clone->value == stack_a->value)
            {
                stack_a->pos = clone->pos;
                break;
            }
            stack_a = stack_a->next;
        }
        stack_a = temp;
        clone = clone->next;
    }
}

// Checks if stack_a is already sorted and exits if true
void    if_sorted(t_list *stack_a, t_list *clone)
{
    t_list  *head_a;
    t_list  *head_c;

    head_a = stack_a;
    head_c = clone;
    while (stack_a && clone)
    {
        if (stack_a->value != clone->value)
            return;
        stack_a = stack_a->next;
        clone = clone->next;
    }
    if (!stack_a && !clone)
    {
        free_lst(head_a);
        free_lst(head_c);
        exit (0);
    }
}

// Pushes from one stack to another, it is a helper function for movements
void	push(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (!*b)
	{
		tmp->next = NULL;
		*b = tmp;
	}
	else
	{
		tmp->next = *b;
		*b = tmp;
	}
}
