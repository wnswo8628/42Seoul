/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:56:57 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/08 21:46:03 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation3(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "ss") == 0)
	{
		swap(a);
		swap(b);
		print_op(op);
	}
	else if (ft_strcmp(op, "rr") == 0)
	{
		rotate(a);
		rotate(b);
		print_op(op);
	}
	else if (ft_strcmp(op, "rrr") == 0)
	{
		re_rotate(a);
		re_rotate(b);
		print_op(op);
	}
	else
		print_error(1);
}

void	operation2(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "ra") == 0)
	{
		rotate(a);
		print_op(op);
	}
	else if (ft_strcmp(op, "rb") == 0)
	{
		rotate(b);
		print_op(op);
	}
	else if (ft_strcmp(op, "rra") == 0)
	{
		re_rotate(a);
		print_op(op);
	}
	else if (ft_strcmp(op, "rrb") == 0)
	{
		re_rotate(b);
		print_op(op);
	}
	else
		operation3(a, b, op);
}

void	operation(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
	{
		swap(a);
		print_op(op);
	}
	else if (ft_strcmp(op, "sb") == 0)
	{
		swap(b);
		print_op(op);
	}
	else if (ft_strcmp(op, "pa") == 0)
	{
		push(a, b);
		print_op(op);
	}
	else if (ft_strcmp(op, "pb") == 0)
	{
		push(b, a);
		print_op(op);
	}
	else
		operation2(a, b, op);
}
