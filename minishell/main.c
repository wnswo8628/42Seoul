/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:32:04 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/15 16:19:04 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_token(t_token	*token, int token_cnt)
{
	int	i;

	i = 0;
	while (i < token_cnt)
	{
		token[i].arr = NULL;
		token[i].infile = NULL;
		token[i].outfile = NULL;
		token[i].cmd = NULL;
		token[i].here_doc = NULL;
		token[i].last_doc = NULL;
		token[i].append_flg = NULL;
		token[i].tav = NULL;
		token[i].fd[0] = -1;
		token[i].fd[1] = -1;
		i++;
	}
}

t_token	*make_token(char *str, int *token_cnt)
{
	t_token	*token;
	char	**split_q;
	int		i;

	i = -1;
	split_q = q_split(str, '|');
	while (split_q[++i])
		(*token_cnt)++;
	token = (t_token *)malloc(sizeof(t_token) * (i + 1));
	token[i].str = NULL;
	while (--i >= 0)
	{
		token[i].str = ft_strdup(split_q[i]);
		free(split_q[i]);
	}
	free(split_q);
	return (token);
}

void	signal_hander(int signo)
{
	if (signo == SIGINT)
	{
		write (1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ctl_signal(int sig_in, int sig_out)
{
	if (sig_in == 0)
		signal(SIGINT, signal_hander);
	if (sig_in == 1)
		signal(SIGINT, SIG_IGN);
	if (sig_in == 2)
		signal(SIGINT, SIG_DFL);
	if (sig_out == 0)
		signal(SIGQUIT, signal_hander);
	if (sig_out == 1)
		signal(SIGQUIT, SIG_IGN);
	if (sig_out == 2)
		signal(SIGQUIT, SIG_DFL);
}

int	main(int ac, char **av, char **env)
{
	char			*str;
	struct termios	term;
	t_token			*token;
	int				token_cnt;
	char			**copy_env;

	check_ac(ac);
	copy_env = set_main(ac, av, &term, env);
	while (42)
	{
		token_cnt = 0;
		str = readline("minishell $ ");
		if (!str)
			ctrl_d();
		if (check_syntax(str))
			continue ;
		add_history(str);
		token = make_token(str, &token_cnt);
		init_token(token, token_cnt);
		if (parse_token(token, token_cnt, str, copy_env))
			continue ;
		execute(token, copy_env, str, token_cnt);
	}
	free_cnvp(copy_env, 0);
}
