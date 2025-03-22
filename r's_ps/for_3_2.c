/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_3_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:42:54 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/07 20:18:31 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	int	num1;
	int	num2;

	num1 = (*a)->content;
	num2 = (*a)->next->content;
	if (num1 > num2)
		sa(a, false);
}

void	sort_3(t_stack **a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*a)->content;
	num2 = (*a)->next->content;
	num3 = (*a)->next->next->content;
	if (num1 < num2 && num2 < num3 && num1 < num3)
		return ;
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(a, false);
		ra(a, false);
	}
	else if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(a, false);
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(a, false);
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(a, false);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa(a, false);
		rra(a, false);
	}
}

bool	sorted(t_stack *a)
{
	if (!a)
		return (true);
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}
