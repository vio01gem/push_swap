/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:04 by hbasheer          #+#    #+#             */
/*   Updated: 2025/04/03 16:25:31 by hajmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pushes all elements from b back to a
void    merge_back(t_list **a, t_list **b)
{
    while (*b)
        pa(a, b);
}

// Sorts the stack using radix sort for larger sizes
void    radix_sort(t_list **a, t_list **b, int len)
{
    int bit_pos;
    int max_pos;
    int count;
    int shift;

    max_pos = len - 1; // Max pos value
    bit_pos = 0;
    while (max_pos >> bit_pos) // Count bits needed
        bit_pos++;
    shift = 0;
    while (shift < bit_pos)
    {
        count = 0;
        while (count < len)
        {
            if (((*a)->pos >> shift) & 1) // Bit is 1
                ra(a);
            else                          // Bit is 0
                pb(a, b);
            count++;
        }
        merge_back(a, b);
        shift++;
    }
}
