/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:51:39 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 17:11:06 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->top->content;
	second = a->top->next->content;
	third = a->top->next->next->content;
	if (first > second && second > third && first > third)
	{
		operation(a, b, "sa");
		operation(a, b, "rra");
	}
	else if (first > second && second < third && first < third)
		operation(a, b, "sa");
	else if (first > second && second < third && first > third)
		operation(a, b, "ra");
	else if (first < second && second > third && first < third)
	{
		operation(a, b, "sa");
		operation(a, b, "ra");
	}
	else if (first < second && second > third && first > third)
		operation(a, b, "rra");
}

void	sort_two(t_stack *a, t_stack *b)
{
	if (a->top->content > a->top->next->content)
		operation(a, b, "sa");
}

void	simple_sort(t_stack *a, t_stack *b)
{
	if (a->cnt == 3)
		sort_three(a, b);
	else if (a->cnt == 2)
		sort_two(a, b);
	else
		return ;
}
