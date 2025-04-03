/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:12 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/03 09:11:55 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    int             value;
    int             pos;
    struct s_list   *next;
}                   t_list;

//error_function.c//
void    print_string(char *s);
void    exit_with_error(void);
void    free_all(t_list *lst);
void    free_array(char **arr);

//utils1.c//
char    *ft_strdup(const char *src);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *s);
long    ft_atoi_bounds(char *str);
int     int_len(int n);
char    *ft_itoa(int n);

//utils2.c//
int     my_count(char const *s, char c);
char    *cpy_word(char const *s, char c, char *str);
char    **allocation(char **array, char const *s, char c);
char    **ft_split(char const *s, char c);

//utils3.c//
t_list  *create_node(int value);
void    stack_add_back(t_list **stack, t_list *new);
int     has_duplicate(t_list *stack, int value);
t_list  *build_stack(char **numbers);

//parse_arguments.c//
int     check_valid(char *str);
char    **parse_input(char **av);

#endif