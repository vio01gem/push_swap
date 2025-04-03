/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:12 by hajmoham          #+#    #+#             */
/*   Updated: 2025/04/03 20:01:58 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
    int             value; //the value of the content 
    int             pos; // the position (index)
    struct s_list   *next; // pointer to the next node
}                   t_list;

//error_function.c//
void    print_string(char *s);
void    exit_with_error(t_list *lst, char **arr);
void    free_lst(t_list *lst);
void    free_array(char **arr);

//utils_1.c//
char    *ft_strdup(const char *src);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *s);
long    ft_atoi_bounds(char *str);
void    index_cloner(t_list *stack);


//utils_2.c//
int     my_count(char const *s, char c);
char    *cpy_word(char const *s, char c, char *str);
char    **allocation(char **array, char const *s, char c);
char    **ft_split(char const *s, char c);

//utils_3.c//
t_list  *create_node(int value);
void    stack_add_back(t_list **stack, t_list *new);
int     has_duplicate(t_list *stack, int value);
t_list  *build_stack(char **numbers);
int     ft_lstsize(t_list *lst);

//utils_4.c//
t_list  *clone_stack(t_list *stack);
void    sort_clone(t_list *stack);
void  	assign_pos(t_list *stack_a, t_list *clone);
void    if_sorted(t_list *stack_a, t_list *clone);
void	push(t_list **a, t_list **b);

//parse_arguments.c//
int		is_empty(char *av);
int     check_valid(char *str);
char    **parse_input(char **av);


//movements.c//
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	sa(t_list **a);
void	ra(t_list **a);
void	rra(t_list **a);

//mini_sorting.c//
int     get_pos(t_list *stack, int target);
void	three_sort(t_list **a);
void	four_sort(t_list **a, t_list **b);
void    five_sort(t_list **a, t_list **b);
void    sort_stack(t_list **a, t_list **b);

//radix.c//
void	merge_back(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b, int size);

#endif