/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:34:20 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/07 19:26:49 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parsing(int arg_count, char **av)
{
	int		i;
	char	*arg;
	char	*tmp;
	char	**split;

	if (!arg_count || !av || !*av)
		return (ft_putstr_fd(ERROR_ARGS, 2), NULL);
	i = 1;
	if (!check_empty(av))
		return (ft_putstr_fd(ERROR_ARGS, 2), NULL);
	arg = ft_strjoin(av[i], " ");
	i++;
	while (av[i])
	{
		tmp = ft_strjoin(arg, av[i]);
		free(arg);
		arg = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	split = ft_split(arg, ' ');
	free(arg);
	check_input(split);
	return (split);
}

int	ft_conlong(char *str, int *flag)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1) || (number > 2147483647
			&& sign == 1))
	{
		*flag = 0;
		return (0);
	}
	return (number * sign);
}

static int	is_valid_number(char *str)
{
	if (*str == '\0' || *str == '\n')
		return (1);
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (1);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	check_input(char **av)
{
	int	i;

	i = 0;
	if (av[0] == NULL)
		spit_out_error();
	while (av[i])
	{
		if (is_valid_number(av[i]))
		{
			free_str(av);
			spit_out_error();
		}
		i++;
	}
	return (1);
}

int	handle_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
