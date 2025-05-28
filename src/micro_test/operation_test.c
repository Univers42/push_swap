/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:48:40 by dlesieur          #+#    #+#             */
/*   Updated: 2025/05/28 17:48:44 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Helper function to print a stack
void print_stack(t_list *stack, char stack_name)
{
    ft_printf("Stack %c: ", stack_name);
    if (!stack)
    {
        ft_printf("(empty)\n");
        return;
    }
    
    while (stack)
    {
        ft_printf("%d ", *(int *)stack->content);
        stack = stack->next;
    }
    ft_printf("\n");
}

// Helper function to create a node with integer content
t_list *create_int_node(int value)
{
    int *content = malloc(sizeof(int));
    if (!content)
        return (NULL);
    *content = value;
    return (ft_lstnew(content));
}

int main(int argc, char **argv)
{
    t_ps ps;
    t_list *node;
    int i;

    // Initialize the push_swap structure
    ps.stack_a = NULL;
    ps.stack_b = NULL;
    ps.size_a = 0;
    ps.size_b = 0;

    if (argc == 1)
    {
        ft_printf("Usage: %s <numbers>\n", argv[0]);
        return (1);
    }

    // Build stack A from command line arguments
    i = argc - 1;
    while (i >= 1)  // Build in reverse to maintain order
    {
        node = create_int_node(ft_atoi(argv[i]));
        if (!node)
            return (1);
        ft_lstadd_front(&ps.stack_a, node);
        ps.size_a++;
        i--;
    }
    ps.total_size = ps.size_a;

    // Display initial state
    ft_printf("\n=== INITIAL STATE ===\n");
    print_stack(ps.stack_a, 'A');
    print_stack(ps.stack_b, 'B');
    ft_printf("Size A: %d, Size B: %d\n\n", ps.size_a, ps.size_b);

    // Test pb operations
    ft_printf("=== TESTING PB OPERATIONS ===\n");
    pb(&ps);
    print_stack(ps.stack_a, 'A');
    print_stack(ps.stack_b, 'B');
    ft_printf("Size A: %d, Size B: %d\n\n", ps.size_a, ps.size_b);

    pb(&ps);
    print_stack(ps.stack_a, 'A');
    print_stack(ps.stack_b, 'B');
    ft_printf("Size A: %d, Size B: %d\n\n", ps.size_a, ps.size_b);

    // Test pa operations
    ft_printf("=== TESTING PA OPERATIONS ===\n");
    pa(&ps);
    print_stack(ps.stack_a, 'A');
    print_stack(ps.stack_b, 'B');
    ft_printf("Size A: %d, Size B: %d\n\n", ps.size_a, ps.size_b);

    pa(&ps);
    print_stack(ps.stack_a, 'A');
    print_stack(ps.stack_b, 'B');
    ft_printf("Size A: %d, Size B: %d\n\n", ps.size_a, ps.size_b);

    // Test edge case: pb when A is empty
    ft_printf("=== TESTING EDGE CASE: PB WHEN A IS EMPTY ===\n");
    pb(&ps);  // Should do nothing
    print_stack(ps.stack_a, 'A');
    print_stack(ps.stack_b, 'B');
    ft_printf("Size A: %d, Size B: %d\n\n", ps.size_a, ps.size_b);

    // Cleanup (you'll need to implement this)
    ft_lstclear(&ps.stack_a, free);
    ft_lstclear(&ps.stack_b, free);

    return (0);
}