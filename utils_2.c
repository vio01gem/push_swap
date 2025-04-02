/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:40:16 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/02 11:03:18 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Counts the number of words in a string separated by a delimiter
int my_count(char const *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        if (s[i] != c && (i == 0 || s[i - 1] == c))
            count++;
        i++;
    }
    return (count);
}

// Copies a word from a string until the delimiter or end
char    *cpy_word(char const *s, char c, char *str)
{
    int i;

    i = 0;
    while (s[i] && s[i] != c)
        i++;
    str = malloc((i + 1) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (s[i] && s[i] != c)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

// Allocates and fills an array of strings split by a delimiter
char    **allocation(char **array, char const *s, char c)
{
    int i;
    int count;

    count = my_count(s, c);
    array = malloc(sizeof(char *) * (count + 1));
    if (!array)
        return (NULL);
    i = 0;
    while (i < count)
    {
        while (*s == c)
            s++;
        array[i] = cpy_word(s, c, array[i]);
        if (!array[i])
        {
            free_array(array);
            return (NULL);
        }
        while (*s && *s != c)
            s++;
        i++;
    }
    array[i] = NULL;
    return (array);
}

// Splits a string by a delimiter into an array of strings
char    **ft_split(char const *s, char c)
{
    char    **array;

    array = NULL;
    if (!s)
        return (NULL);
    array = allocation(array, s, c);
    return (array);
}
