/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:40:36 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/06 10:12:33 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	while (head->next != NULL)
	{
		tmp = head;
		head = head->next;
	}
	head->next = *stack;
	tmp->next = NULL;
	*stack = head;
}

void	rra(t_stack **a, bool checker)
{
	r_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool checker)
{
	r_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	r_rotate(a);
	r_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
