/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:25:08 by jugwak            #+#    #+#             */
/*   Updated: 2023/03/11 18:36:28 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		min;
	int		max[3];
	int		cnt;
}	t_stack;

typedef struct s_op_cnt
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	char	min_type;
	int		min_cnt;
	t_node	*node;
}	t_op_cnt;

void	simple_sort(t_stack *a, t_stack *b);
void	sa(t_stack *stack);
int		ft_atoi(const char *str);
char	**ft_split(char const *str, char c);
size_t	ft_strlen(const char *str);
int		ft_isalnum(int c);
int		print_error(int type);
int		ft_strcmp(const char *s1, const char *s2);
void	operation(t_stack *a, t_stack *b, char *op);
t_node	*getnode(t_node *next, int elem);
void	add_last(t_stack *a, int elem);
void	get_input_num(t_stack *a, int *array_num, int size);
void	add_node(t_stack *stack, int elem);
int		remove_node(t_stack *stack);
int		ft_max(int n, int m);
int		ft_min(int n, int m);
void	choose_best_con(t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	choose_min_op(t_node *node, t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	count_op_b(t_node *node, t_stack *b, t_op_cnt *op_cnt);
void	count_op_a(t_node *node, t_stack *a, t_op_cnt *op_cnt);
void	set_a_max(t_stack *a);
void	pb_best_con(t_stack *a, t_stack *b, t_op_cnt *op_cnt);
void	pb_best_con_sub(t_stack *a, t_stack *b, t_op_cnt *op_cnt);
int		loop_operation(t_stack *a, t_stack *b, int cnt, char *op);
void	set_b_max_top(t_stack *a, t_stack *b);
void	sort_three(t_stack *a, t_stack *b);
void	re_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	push(t_stack *a, t_stack *b);
void	print_op(char *op);
void	swap(t_stack *stack);
void	free_str(char **snum);
void	check_double(int *num, int n, int size, int i);
void	check_sort(int *num, int size);
int		*get_num_array(int ac, char **av, int size);
int		get_str_size(int ac, char **av);
int		get_split_size(char **snum);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif