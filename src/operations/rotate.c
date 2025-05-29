/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:31:43 by dlesieur          #+#    #+#             */
/*   Updated: 2025/05/29 15:02:51 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/stack.h"
/**
 * move all the element up above til the first element is found the ultimate one
 * @param 
 */
static void     rotate_stack(t_list **stack);

void ra(t_ps *ps)
{
    rotate_stack(&ps->stack_a);
    ft_printf("ra\n");
}

void rb(t_ps *ps)
{
    rotate_stack(&ps->stack_b);
    ft_printf("rb\n");
}

void rr(t_ps *ps)
{
    rotate_stack(&ps->stack_a);
    rotate_stack(&ps->stack_b);
    ft_printf("rr\n");
}

static void rotate_stack(t_list **stack)
{
    t_list *first;
    t_list *last;
    
    if (!stack || !*stack || !(*stack)->next)
        return;
    
    first = *stack;
    last = ft_lstlast(*stack);
    
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}