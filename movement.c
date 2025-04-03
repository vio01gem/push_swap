/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:46:35 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/03 15:02:51 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push to B  (First on top of Stack A to Stack B)
void	pb(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

// Push to A (First on top of Stack B to Stack A)
void	pa(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

// Swap A (first on top to second)
void	sa(t_list **a)
{
	t_list	*swap;

	if (!*a || ft_lstsize(*a) < 2)
		return ;
	swap = *a;
	*a = swap->next;
	swap->next = (*a)->next;
	(*a)->next = swap;
	write(1, "sa\n", 3);
}

// Rotate A (First on top to bottom)
void    ra(t_list **a)
{
    t_list  *top;
    t_list  *bottom;

    if (!*a || ft_lstsize(*a) == 1)
        return;
    top = *a;
    bottom = *a;
    while (bottom->next)
        bottom = bottom->next;
    *a = top->next;
    top->next = NULL;
    bottom->next = top;
    write(1, "ra\n", 3);
}

// Reverse Rotate A (Last to First on bottom)
void    rra(t_list **a)
{
    t_list  *prev;
    t_list  *bottom;

    if (!*a || ft_lstsize(*a) == 1)
        return;
    prev = *a;
    while (prev->next->next)
        prev = prev->next;
    bottom = prev->next;
    prev->next = NULL;
    bottom->next = *a;
    *a = bottom;
    write(1, "rra\n", 4);
}

