/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:03 by hajmoham          #+#    #+#             */
/*   Updated: 2025/03/24 18:33:53 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>


// int	main(int ac, char **av)
// {
// 	if (ac < 2)
// 		return (0);
// 	if (ac == 2 && !av[1][0])
// 		print_error();
// 	av = parcing(av);
// 	return (0);
// }

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_put_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	print_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		ft_put_str(args[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	char **splited;
	int i = 0;

	if (ac < 2)
		return (0);
	splited = parcing(av);

	while (splited[i])
	{
		ft_put_str("Parsed: ");
		ft_put_str(splited[i]);
		ft_put_str("\n");

		if (!is_valid_input(splited[i]))
		{
			write(2, "Error\n", 6);
			// Free memory
			i = 0;
			while (splited[i])
				free(splited[i++]);
			free(splited);
			return (1);
		}
		i++;
	}

	// Optional: print all parsed numbers
	print_args(splited);

	// Free memory
	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
	return (0);
}


