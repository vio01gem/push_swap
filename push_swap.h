/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:50:12 by hajmoham          #+#    #+#             */
/*   Updated: 2025/03/24 18:28:46 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack
{
    int *data;
    int size;
}   t_stack;


int is_valid_input(char *str);
char **parcing (char **av);

void	ft_put_str(char *s);

#endif
