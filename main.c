/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:03 by hajmoham          #+#    #+#             */
/*   Updated: 2025/03/21 14:28:09 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack;
	int i, value;

	if (ac < 2)
		return (0);

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	stack->a = NULL;
	stack->b = NULL;
	stack->size = 0;

	i = 1;
	while (i < ac)
	{
		if (!is_valid_number(av[i]))
			print_error(stack);
		value = ft_atoi(av[i], stack);
		push_stack(&stack->a, value);
		stack->size++;
		i++;
	}
	if (has_duplicates(stack->a))
		print_error(stack);

	// TODO: Sorting logic goes here...

	free_all(stack);
	return (0);
}

