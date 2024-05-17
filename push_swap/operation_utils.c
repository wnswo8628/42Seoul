/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:29:10 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:10:20 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_rotate(t_stack *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	if (stack->cnt <= 1)
		return ;
	ptr = stack->top;
	while (ptr->next)
	{
		if (ptr->next->next == NULL)
			tmp = ptr;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	ptr->next = stack->top;
	stack->top = ptr;
}

void	rotate(t_stack *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	if (stack->cnt <= 1)
		return ;
	ptr = stack->top;
	tmp = stack->top->next;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = stack->top;
	ptr->next->next = NULL;
	stack->top = tmp;
}

void	push(t_stack *a, t_stack *b)
{
	if (b->cnt == 0)
		return ;
	add_node(a, remove_node(b));
}

void	print_op(char *op)
{
	write (1, op, ft_strlen(op));
	write (1, "\n", 1);
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->cnt <= 1)
		return ;
	tmp = stack->top->content;
	stack->top->content = stack->top->next->content;
	stack->top->next->content = tmp;
}
