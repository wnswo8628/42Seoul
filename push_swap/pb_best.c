/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_best.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:08:08 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:10:52 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loop_operation(t_stack *a, t_stack *b, int cnt, char *op)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		operation(a, b, op);
		i++;
	}
	return (i);
}

void	set_b_max_top(t_stack *a, t_stack *b)
{
	int		i;
	int		cnt;
	int		tmp;
	t_node	*ptr;

	i = 0;
	tmp = -2147483648;
	ptr = b->top;
	while (ptr)
	{
		if (ptr->content >= tmp)
		{
			tmp = ptr->content;
			cnt = i;
		}
		i++;
		ptr = ptr->next;
	}
	if (cnt < (b->cnt - cnt) % b->cnt)
		loop_operation(a, b, cnt, "rb");
	else
		loop_operation(a, b, (b->cnt - cnt) % b->cnt, "rrb");
}

void	pb_best_con_sub(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	if (op_cnt->ra < op_cnt->rra)
		loop_operation(a, b, op_cnt->ra, "ra");
	else
		loop_operation(a, b, op_cnt->rra, "rra");
	if (op_cnt->rb < op_cnt->rrb)
		loop_operation(a, b, op_cnt->rb, "rb");
	else
		loop_operation(a, b, op_cnt->rrb, "rrb");
}

void	pb_best_con(t_stack *a, t_stack *b, t_op_cnt *op_cnt)
{
	int	cnt;

	if (op_cnt->min_type == 1)
	{
		cnt = loop_operation(a, b, ft_min(op_cnt->ra, op_cnt->rb), "rr");
		if (op_cnt->ra > op_cnt->rb)
			loop_operation(a, b, op_cnt->ra - cnt, "ra");
		else
			loop_operation(a, b, op_cnt->rb - cnt, "rb");
	}
	else if (op_cnt->min_type == 2)
	{
		cnt = loop_operation(a, b, ft_min(op_cnt->rra, op_cnt->rrb), "rrr");
		if (op_cnt->rra > op_cnt->rrb)
			loop_operation(a, b, op_cnt->rra - cnt, "rra");
		else
			loop_operation(a, b, op_cnt->rrb - cnt, "rrb");
	}
	else
		pb_best_con_sub(a, b, op_cnt);
	operation(a, b, "pb");
}
