/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:37:54 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/09 13:15:51 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}
