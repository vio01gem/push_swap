/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:26:42 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/12 17:32:03 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *a, t_stack *b)
{
	ft_stack_clear(&a);
	ft_stack_clear(&b);
}

void	decide(t_stack **a, t_stack **b)
{
	int	length;

	length = len_stack(*a);
	if (length == 2)
		sort_2(a);
	else if (length == 3)
		sort_3(a);
	else if (length == 4 || length == 5)
		sort_4_5(a, b);
	else
		bits_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	if (ac == 2 && !av[1][0])
		spit_out_error();
	a = NULL;
	b = NULL;
	av = parsing(ac - 1, av);
	if (!av)
		return (1);
	stack_build(&a, av);
	if (!sorted(a))
	{
		decide(&a, &b);
	}
	free_stack(a, b);
	return (0);
}
