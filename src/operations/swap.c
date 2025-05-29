/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:03:15 by dlesieur          #+#    #+#             */
/*   Updated: 2025/05/29 15:03:16 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * @note RULES OF THUMB, if we need to modify the pointer variable that was passed in
 * , meaning making it point somehwere else, we use double pointer. 
 * If we just need to access modify waht it points to, use single pointer
 */
static void swap(t_list *source, int size_src)
{
    t_list *temp;

    if (!source || !source->next || size_src == 0)
        return ;
    temp = source->content;
    source->content = source->next->content;
    source->next->content = temp;
}

void   sa(t_ps *ps)
{
    swap(ps->stack_a, ps->size_a);
    ft_printf("sa\n");
}

void   sb(t_ps *ps)
{
    swap(ps->stack_b, ps->size_b);
    ft_printf("sb\n");
}

void   ss(t_ps *ps)
{
    sa(ps);
    sb(ps);
}