/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:20:56 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/03 16:45:35 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
// Finds the position of a node with the given pos value
int get_pos(t_list *stack, int target)
{
    int count;

    count = 0;
    while (stack)
    {
        if (stack->pos == target)
            return (count);
        stack = stack->next;
        count++;
    }
    return (count);
}

// Sorts a stack of 3 elements
void    three_sort(t_list **a)
{
    int one;
    int two;
    int three;

    one = (*a)->pos;
    two = (*a)->next->pos;
    three = (*a)->next->next->pos;
    if (one == 0 && two == 2 && three == 1)      // 0 2 1
    {
        rra(a);
        sa(a);
    }
    else if (one == 1 && two == 0 && three == 2) // 1 0 2
        sa(a);
    else if (one == 1 && two == 2 && three == 0) // 1 2 0
        rra(a);
    else if (one == 2 && two == 1 && three == 0) // 2 1 0
    {
        ra(a);
        sa(a);
    }
    else if (one == 2 && two == 0 && three == 1) // 2 0 1
        ra(a);
}

// Sorts a stack of 4 elements
void    four_sort(t_list **a, t_list **b)
{
    int spot;
    int len;

    spot = get_pos(*a, 3); // Find pos=3 (max)
    len = ft_lstsize(*a);
    if (spot < len / 2)
    {
        while (spot > 0)
        {
            ra(a);
            spot--;
        }
    }
    else
    {
        while (spot < len)
        {
            rra(a);
            spot++;
        }
    }
    pb(a, b);
    three_sort(a);
    pa(a, b);
    ra(a);
}

// Sorts a stack of 5 elements
void    five_sort(t_list **a, t_list **b)
{
    int spot;
    int len;

    spot = get_pos(*a, 4); // Find pos=4 (max)
    len = ft_lstsize(*a);
    if (spot < len / 2)
    {
        while (spot > 0)
        {
            ra(a);
            spot--;
        }
    }
    else
    {
        while (spot < len)
        {
            rra(a);
            spot++;
        }
    }
    pb(a, b);
    four_sort(a, b);
    pa(a, b);
    ra(a);
}

// Main sorting function for small stacks
void    sort_stack(t_list **stack_a, t_list **stack_b)
{
    int len;

    len = ft_lstsize(*stack_a);
    if (len <= 1)
        return;
    if (len == 2 && (*stack_a)->pos > (*stack_a)->next->pos)
        sa(stack_a);
    else if (len == 3)
        three_sort(stack_a);
    else if (len == 4)
        four_sort(stack_a, stack_b);
    else if (len == 5)
        five_sort(stack_a, stack_b);
    radix_sort(stack_a, stack_b, len);
}
