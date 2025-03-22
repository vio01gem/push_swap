/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:58:28 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/06 11:26:19 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack *lst)
{
	int		count;
	t_stack	*current;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

t_stack	*find_min(t_stack *head)
{
	t_stack	*min_node;
	long	min_value;
	t_stack	*current;

	if (!head)
		return (NULL);
	min_value = LONG_MAX;
	min_node = head;
	current = head;
	while (current)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

void	ft_stack_clear(t_stack **lst)
{
	t_stack	*ptr;
	t_stack	*temp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}

void	ft_stack_add_back(t_stack **head, t_stack *new_node)
{
	t_stack	*tail;

	if (!head || !new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new_node;
}
