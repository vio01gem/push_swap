/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:31:49 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/02 09:31:49 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prints a string to stdout character by character
void    print_string(char *s)
{
    int i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    free(s);
}

// Exits the program with an "Error" message to stderr
void    terminate_with_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

// Frees the entire linked list
void    free_all(t_list *lst)
{
    t_list  *temp;

    temp = lst;
    while (lst != NULL)
    {
        lst = lst->next;
        free(temp);
        temp = lst;
    }
}

// Frees a dynamically allocated array of strings
void    free_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
