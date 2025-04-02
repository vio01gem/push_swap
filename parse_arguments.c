/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:11:16 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/02 15:40:03 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Checks spaces or null
int		is_empty(char *av)
{
    int		i;
	i = 0;
    if (!av[0])
        return (1);
    while (av[i])
    {
        if (av[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

// Checks if a string is a valid number (digits with optional +/-) and within int bounds
int     check_valid(char *str)
{
    int     i;
    long    num;
    int     digit;

    i = 0;
    digit = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i]) // Empty string or just a sign
        return (0);
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit = 1;
        else if (str[i] != ' ' && str[i] != '\t') // Non-digit, non-whitespace
            return (0);
        i++;
    }
    if (!digit) // No digits found
        return (0);
    num = ft_atoi_bounds(str);
    if (num > 2147483647 || num < -2147483648)
        return (0);
    return (1);
}

// Parses arguments by joining with spaces, splitting, and returning the array
char    **parse_input(char **av)
{
    char    *joined;
    char    *temp;
    char    **splitted;
    int     i;
    
    joined = ft_strdup("");
    i = 1;
    while (av[i])
    {
        if (is_empty(av[i]))
        {
            write (2, "empty string found\n", 19);
            terminate_with_error();
        }
        temp = ft_strjoin(joined, " ");
        joined = ft_strjoin(temp, av[i]);
        i++;
    }
    splitted = ft_split(joined, ' ');
    free(joined);
    return (splitted);
}
