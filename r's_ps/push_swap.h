/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:31:28 by rradin-m          #+#    #+#             */
/*   Updated: 2025/02/12 15:56:05 by rradin-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define ERROR_MESSAGE "Error\n"
#define ERROR_ARGS "Error\n"

typedef struct s_stack
{
	int				content;
	int				index;
	bool			above_median;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/* @brief Checking inputs. */
int					check_input(char **str);
/* @brief Converting different variables into different string using split. */
char				**parsing(int arg_count, char **args);
/* @brief Converting strings to integer including, INT MAX & INT MIN. */
int					ft_conlong(char *str, int *flag);
/* @brief Check integer duplicates. */
int					handle_repetition(t_stack *a, int nbr);
/* @brief Build a stack. */
void				stack_build(t_stack **a, char **str);

/* @brief Swap first two in a. */
void				sa(t_stack **a, bool print);
/* @brief Swap first two in b. */
void				sb(t_stack **b, bool print);
/* @brief Swap first two both a and b. */
void				ss(t_stack **a, t_stack **b, bool print);

/* @brief Push to a. */
void				pa(t_stack **a, t_stack **b, bool print);
/* @brief Push to b. */
void				pb(t_stack **a, t_stack **b, bool print);

/* @brief Rotates. */
void				ra(t_stack **a, bool print);
/* @brief Rotates. */
void				rb(t_stack **b, bool print);
/* @brief Rotates. */
void				rr(t_stack **a, t_stack **b, bool print);

/*  @brief Reverse rotate. */
void				rra(t_stack **a, bool print);
/*  @brief Reverse rotate. */
void				rrb(t_stack **b, bool print);
/* @brief Reverse rotate. */
void				rrr(t_stack **a, t_stack **b, bool print);

/* @brief  2 integers */
void				sort_2(t_stack **a);
/* @brief sort 3 integers */
void				sort_3(t_stack **a);
/* @brief sort 4 or 5 integers */
void				sort_4_5(t_stack **a, t_stack **b);
/* @brief Check the stack is sorted. */
bool				sorted(t_stack *a);

/* @brief Radix sorting algorithm using bits of index. */
void				bits_sort(t_stack **stack_a, t_stack **stack_b);
/* @brief Helps radix sort as assigning index in a sorted order. */
void				index_assigning(t_stack **stack);
/* @brief Calculates the maximum number of bits. */
int					get_max_bits(t_stack *stack);
/* @brief Find the smallest value with index is -1. */
t_stack				*find_min_radix(t_stack **stack);

/*
	@brief helps to check the given string is empty.
	@param char
	@return 0 if the string is empty else 1.
*/
int					check_empty(char **str);

/* @brief Add a new node to the end of a linked list.   */
void				ft_stack_add_back(t_stack **lst, t_stack *newnode);
/* @brief find the length of a stack. */
int					len_stack(t_stack *lst);
/* @brief Find smallest value in the stack. */
t_stack				*find_min(t_stack *stack);
/* @brief Free allocated memory for stacks. */
void				ft_stack_clear(t_stack **lst);

/* @brief  Free allocated memory for strings. */
void				free_str(char **str);
/* @brief A libft function with more handlings. */
void				putstr_fd(char *s, int fd);
/* @brief Print "ERROR\n" message. */
void				spit_out_error(void);