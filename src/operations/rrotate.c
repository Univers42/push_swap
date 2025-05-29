/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:19:42 by dlesieur          #+#    #+#             */
/*   Updated: 2025/05/29 15:03:01 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/stack.h"
#include "../inc/push_swap.h"
#include "../inc/stack.h"

/**
 * Move the last element to the front (reverse rotate)
 */
static void reverse_rotate_stack(t_list **stack);

void rra(t_ps *ps)
{
    reverse_rotate_stack(&ps->stack_a);
    ft_printf("rra\n");
}

void rrb(t_ps *ps)
{
    reverse_rotate_stack(&ps->stack_b);
    ft_printf("rrb\n");
}

void rrr(t_ps *ps)
{
    reverse_rotate_stack(&ps->stack_a);
    reverse_rotate_stack(&ps->stack_b);
    ft_printf("rrr\n");
}

static void reverse_rotate_stack(t_list **stack)
{
    t_list *last;
    t_list *second_last;
    
    if (!stack || !*stack || !(*stack)->next)
        return;
    second_last = *stack;
    while (second_last->next && second_last->next->next)
        second_last = second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
}