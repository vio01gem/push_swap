/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:43:58 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/12 20:05:42 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	stacking(t_stack **a, int num)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!a)
		return ;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return ;
	tmp->content = num;
	tmp->index = -1;
	tmp->next = NULL;
	if (!(*a))
	{
		*a = tmp;
		tmp->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = tmp;
		tmp->prev = last_node;
	}
}

void	stack_build(t_stack **a, char **str)
{
	int		i;
	long	num;
	int		flag;

	if (!str)
		return ;
	i = 0;
	flag = 1;
	while (str[i])
	{
		num = ft_conlong(str[i], &flag);
		if (flag == 0)
			return (free_str(str), ft_stack_clear(a), spit_out_error());
		if (handle_repetition(*a, (int)num))
			return (free_str(str), ft_stack_clear(a), spit_out_error());
		stacking(a, (int)num);
		i++;
	}
	free_str(str);
}
