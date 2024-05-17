/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:27:00 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:11:15 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	remove_node(t_stack *stack)
{
	int		con;
	t_node	*ptr;

	ptr = stack->top;
	con = ptr->content;
	stack->top = stack->top->next;
	free(ptr);
	stack->cnt--;
	return (con);
}

void	add_node(t_stack *stack, int elem)
{
	t_node	*ptr;

	ptr = getnode(stack->top, elem);
	if (!ptr)
		print_error(1);
	ptr->next = stack->top;
	stack->top = ptr;
	if (elem > stack->max[0])
		stack->max[0] = elem;
	if (elem < stack->min)
		stack->min = elem;
	stack->cnt++;
}

t_node	*getnode(t_node *next, int elem)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	new->content = elem;
	new->next = next;
	return (new);
}

void	add_last(t_stack *a, int elem)
{
	t_node	*ptr;

	if (a->top == NULL)
		a->top = getnode(NULL, elem);
	else
	{
		ptr = a->top;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = getnode(NULL, elem);
		if (ptr->next == NULL)
			print_error(1);
	}
	if (elem > a->max[0])
		a->max[0] = elem;
	if (elem < a->min)
		a->min = elem;
	a->cnt++;
}

void	get_input_num(t_stack *a, int *array_num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		add_last(a, array_num[i]);
		i++;
	}
}
