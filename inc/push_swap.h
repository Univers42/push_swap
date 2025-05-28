/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlesieur <dlesieur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:32:09 by dlesieur          #+#    #+#             */
/*   Updated: 2025/05/28 17:52:07 by dlesieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h"

# define NEWLINE() (write(1,"\n",1))

typedef struct s_ps
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;
	int		size_b;
	int		total_size;
}				t_ps;

void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);

#endif