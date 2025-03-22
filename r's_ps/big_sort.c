/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:37:04 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/12 17:06:59 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	int	max_bits;
	int	num_bits;
	int	num;

	max_bits = 0;
	while (stack)
	{
		num_bits = 0;
		num = stack->index;
		if (num < 0)
			num *= -1;
		while (num > 0)
		{
			num >>= 1;
			num_bits++;
		}
		if (num_bits > max_bits)
			max_bits = num_bits;
		stack = stack->next;
	}
	return (max_bits);
}

t_stack	*find_min_radix(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;
	int		flag;

	flag = 0;
	tmp = NULL;
	head = *stack;
	while (head != NULL)
	{
		if (head->index == -1 && (flag == 0 || (tmp->content > head->content)))
		{
			tmp = head;
			flag = 1;
		}
		head = head->next;
	}
	return (tmp);
}

void	index_assigning(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = find_min_radix(stack);
	index = 0;
	while (current)
	{
		current->index = index++;
		current = find_min_radix(stack);
	}
}

void	bits_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = len_stack(*stack_a);
	index_assigning(stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (*stack_a && (((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b, false);
			else
				ra(stack_a, false);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b, false);
		i++;
	}
}
