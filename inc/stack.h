#ifndef FT_CHECK_STACK_H
#define FT_CHECK_STACK_H
#include "../libft/libft.h"
/**
 * full compatibility approach with the current t_list structure,
 * all functions that use t_list still work
 * we can access the underlying `t_list` directly when needed
 * no breaking chnages to existing code
 * @note strategic use :
 * stck operation(push, pop, rotate)
 * when we need size tracking
 * when we want circular/linear flexibility
 * 
 */
typedef struct s_stack
{
    t_list *head;
    t_list *tail;
    int size;
    bool is_circular;
}               t_stack;
#endif