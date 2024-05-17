/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:03 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 18:33:45 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_op_cnt	op_cnt;

	if (a->cnt <= 3)
	{
		simple_sort(a, b);
		return ;
	}
	while (a->cnt > 3)
	{
		choose_best_con(a, b, &op_cnt);
		pb_best_con(a, b, &op_cnt);
	}
	set_b_max_top(a, b);
	sort_three(a, b);
	while (b->top)
		operation(a, b, "pa");
}

int	print_error(int type)
{
	if (type >= 1)
	{
		write (2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->max[0] = -2147483648;
	stack->min = 2147483647;
	stack->cnt = 0;
}

void	free_stack(t_stack *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = stack->top;
	if (!ptr)
		return ;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
}

int	main(int ac, char **av)
{	
	int		size;
	int		*num_array;
	t_stack	a;
	t_stack	b;

	if (ac < 2)
	{
		print_error(-1);
	}
	init_stack(&a);
	init_stack(&b);
	size = get_str_size(ac, av);
	num_array = get_num_array(ac, av, size);
	check_sort(num_array, size);
	get_input_num(&a, num_array, size);
	free(num_array);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
