/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:41:17 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/06 10:08:25 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	op_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **a, bool checker)
{
	op_swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool checker)
{
	op_swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	op_swap(a);
	op_swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
