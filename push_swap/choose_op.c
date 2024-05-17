/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:38:46 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:08:44 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_a_max(t_stack *a)
{
	t_node	*ptr;
	int		tmp;

	ptr = a->top;
	tmp = -2147483648;
	while (ptr)
	{
		if (ptr->content < a->max[0] && ptr->content >= tmp)
			tmp = ptr->content;
		ptr = ptr->next;
	}
	a->max[1] = tmp;
	ptr = a->top;
	tmp = -2147483648;
	while (ptr)
	{
		if (ptr->content < a->max[1] && ptr->content >= tmp)
			tmp = ptr->content;
		ptr = ptr->next;
	}
	a->max[2] = tmp;
}

void	count_op_a(t_node *node, t_stack *a, t_op_cnt *op_cnt)
{
	t_node	*ptr;

	if (a->cnt == 0)
		return ;
	ptr = a->top;
	op_cnt->ra = 0;
	while (ptr && (ptr != node))
	{
		ptr = ptr->next;
		op_cnt->ra++;
	}
	op_cnt->rra = a->cnt - op_cnt->ra;
}

void	count_op_b(t_node *node, t_stack *b, t_op_cnt *op_cnt)
{
	t_node	*ptr;
	int		tmp;
	int		i;

	if (b->cnt == 0)
		return ;
	tmp = -2147483648;
	i = 0;
	ptr = b->top;
	while (ptr && ++i)
	{
		if (b->min < node->content && ptr->content
			>= tmp && ptr->content < node->content)
		{
			tmp = ptr->content;
			op_cnt->rb = i - 1;
		}
		if (b->min > node->content && ptr->content >= tmp)
		{
			tmp = ptr->content;
			op_cnt->rb = i - 1;
		}
		ptr = ptr->next;
	}
	op_cnt->rrb = b->cnt - op_cnt->rb;
}

void	choose_min_op(t_node *node, t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	rr;
	int	rrr;
	int	r_rr;

	op_cnt->ra = 0;
	op_cnt->rb = 0;
	op_cnt->rra = 0;
	op_cnt->rrb = 0;
	op_cnt->node = node;
	count_op_a(node, a, op_cnt);
	count_op_b(node, b, op_cnt);
	rr = ft_max(op_cnt->ra, op_cnt->rb);
	rrr = ft_max(op_cnt->rra, op_cnt->rrb);
	r_rr = ft_min(op_cnt->ra, op_cnt->rra) + ft_min(op_cnt->rb, op_cnt->rrb);
	op_cnt->min_cnt = ft_min(rr, rrr);
	op_cnt->min_cnt = ft_min(op_cnt->min_cnt, r_rr);
	if (op_cnt->min_cnt == rr)
		op_cnt->min_type = 1;
	else if (op_cnt->min_cnt == rrr)
		op_cnt->min_type = 2;
	else
		op_cnt->min_type = 3;
}

void	choose_best_con(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	t_node		*ptr;
	t_op_cnt	tmp;

	set_a_max(a);
	ptr = a->top;
	while (ptr->content == a->max[0] || ptr->content == a->max[1]
		|| ptr->content == a->max[2])
		ptr = ptr->next;
	choose_min_op(ptr, a, b, op_cnt);
	ptr = a->top;
	while (ptr)
	{
		choose_min_op(ptr, a, b, &tmp);
		if (tmp.min_cnt < op_cnt->min_cnt && ptr->content != a->max[0]
			&& ptr->content != a->max[1] && ptr->content != a->max[2])
			*op_cnt = tmp;
		ptr = ptr->next;
	}
}
