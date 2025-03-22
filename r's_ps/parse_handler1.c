/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handler1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:36:27 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/07 16:46:17 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

int	check_empty(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	spit_out_error(void)
{
	putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
