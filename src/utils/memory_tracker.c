/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tracker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:54:04 by dlesieur          #+#    #+#             */
/*   Updated: 2025/05/28 16:57:34 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void cleanup_stacks(t_ps *ps)
{
    if (ps->stack_a)
    {
        if (ps->stack_a->stack)
            free(ps->stack_a->stack);
        free(ps->stack_a);
    }
    if (ps->stack_b)
    {
        if (ps->stack_b->stack)
            free(ps->stack_b->stack);
        free(ps->stack_b);
    }
}