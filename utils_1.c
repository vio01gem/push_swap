/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:56:59 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/02 12:29:55 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Duplicates a string using malloc, returns NULL on failure
char    *ft_strdup(const char *src)
{
    char    *str;
    int     i;

    i = 0;
    str = malloc(ft_strlen((char *)src) + 1);
    if (str == NULL)
        return (NULL);
    while (src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

// Joins two strings into a new one, frees s1, returns NULL on failure
char    *ft_strjoin(char *s1, char *s2)
{
    char    *s3;
    int     i;
    int     j;

    j = 0;
    if (!s1 || !s2)
        return (NULL);
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!s3)
        return (NULL);
    i = 0;
    while (s1[i])
        s3[j++] = s1[i++];
    i = 0;
    while (s2[i])
        s3[j++] = s2[i++];
    s3[j] = '\0';
    free(s1);
    return (s3);
}

// Returns the length of a string
int     ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

// Converts a string to a long with bounds checking for int range
long    ft_atoi_bounds(char *str)
{
    long    result;
    int     sign;
    int     i;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (result > 2147483647 && sign == 1)
            return (2147483648);
        if (result > 2147483648 && sign == -1)
            return (2147483649);
        i++;
    }
    return (sign * result);
}

// Calculates the number of digits in an integer, including sign if negative for ft_itoa
int int_len(int n)
{
    int i;

    i = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        i++;
    while (n != 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

// Converts an integer to a string
char    *ft_itoa(int n)
{
    unsigned int    len;
    unsigned int    nb;
    char            *str;

    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    len = int_len(n);
    str = malloc(len + 1);
    if (str == NULL)
        return (NULL);
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    nb = n;
    if (n < 0)
    {
        str[0] = '-';
        nb = -n;
    }
    while (nb != 0)
    {
        str[--len] = '0' + (nb % 10);
        nb = nb / 10;
    }
    return (str);
}

