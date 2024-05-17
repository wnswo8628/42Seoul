/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:32:17 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/13 21:28:41 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <termios.h> //tcgetter함수 사용하기위한 헤더
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>	// opendir
# include "libft/libft.h"

# define CD		1
# define EC		2
# define ENV	3
# define EXIT	4
# define EXPORT	5
# define PWD	6
# define UNSET	7

int	g_status;

typedef struct s_heredoc
{
	int		i;
	int		j;
	int		file_i;
	int		status;
	char	*filename;
	int		idx;
	char	*heredoc;
	char	*str;
	int		fd;
	int		len;
	int		pos;
	pid_t	pid;
}	t_heredoc;

typedef struct s_lenpos
{
	int	j;
	int	i;
	int	len;
	int	pos;
}	t_lenpos;

typedef struct s_split
{
	int		inword;
	int		issep;
	int		i;
	int		cnt;
	int		inquotes;
}	t_split;

typedef struct s_token
{
	char	*str;
	char	**arr;
	char	**infile;
	char	**outfile;
	int		*append_flg;
	int		inre_cnt;
	int		outre_cnt;
	char	*cmd;
	char	**tav;
	char	**here_doc;
	int		heredoc_cnt;
	int		append_cnt;
	int		fd[2];
	int		is_pipe;
	int		in_quotes;
	char	*last_doc;
}	t_token;

typedef struct s_delq
{
	int	oneq_cnt;
	int	twoq_cnt;
	int	index;
	int	pos;
}	t_delq;

void	ft_free(void *str);
int		check_qorp(char *str);
int		find_pipe(char *str, int *i, int *pos);
int		is_spacepipe(char *str);
int		check_syntax(char *str);

void	join_arr(t_token *token, int i, int j, char **arr);
void	shift_q(t_token *token, int i, int j, t_delq *delq);
void	delete_q(t_token *token, int i, int j);
void	doubleq_join(t_token *token, int i, int j);
int		is_dohome(char *str);
void	doubleq_p(char **arr, char **env);
void	parse_option(t_token *token, int i, int j, char **env);
char	*dollar_last(char *str, char *temp);
char	*env_parse(char **env, char *str);
char	*get_env(char **env, char *str);
char	**last_dollar(char *str, char c);
char	**dollar_split(char *str, char c);
void	make_option(t_token *token, int i, char	**env);
void	make_cmd(t_token *token, char *str, t_lenpos index);
int		check_exist(t_token *token, char *str, t_lenpos index);
char	*join_temp(char **result);
char	**splitjoin(t_token *token, int i, char *sep);
void	cmd_parse(t_token *token, int token_cnt, char **env);
int		option_len(char *str);
char	*space_env_parse(char **env, char *str);
int		is_space(char c);

void	get_cnt(char const *s, char c, t_split *p, size_t *pos);
void	get_cwinfo(char const *str, char c, t_split *sp);
size_t	ft_countspell2(char const *s, char c, size_t *pos);
size_t	ft_countword2(char const *str, char c);
int		ft_checkleak2(char **arr, int i);
char	**error_handle(void);
char	**dq_split(char const *str, char c);

void	unlink_file(t_token *token, t_heredoc *hdoc, int token_cnt);
void	wait_heredoc(t_heredoc *hdoc);
void	fork_heredoc(t_token *token, t_heredoc *hdoc, int *status);
int		infile_hd(t_token *token, int i, int j);
void	input_heredoc(t_token *token, t_heredoc *hdoc, int status);
int		file_heredoc(t_token *token, int i, int j);
void	heredoc_ps(t_token *token, t_heredoc *hdoc);
int		heredoc_parse(t_token *token, int token_cnt);

void	init_token(t_token	*token, int token_cnt);
t_token	*make_token(char *str, int *token_cnt);
void	signal_hander(int signo);
void	ctl_signal(int sig_in, int sig_out);
char	**set_main(int ac, char **av, struct termios *term, char **env);
char	**ft_errorhandler(void);

void	parse_append(t_token *token, t_lenpos *lp, int *k);
void	parse_outfile(t_token *token, t_lenpos *lp, int *k);
int		malloc_outre(t_token *token, t_lenpos *lp);
void	outredirect_parse(t_token *token, int token_cnt);

void	print_token(t_token *token, int token_cnt);
void	find_infile(t_token *token, t_lenpos *lp, int *k);
void	inredirect_parse(t_token *token, int token_cnt);
int		is_quotes(t_token *token, char c, int i);
void	match_redirect(t_token *token, int *j, int *i);
void	set_token_cnt(t_token *token, int token_cnt);
int		parse_token(t_token *token, int token_cnt, char *str, char **env);
void	get_inquotes(char c, t_split *sp);
void	init_split(t_split *sp);
int		error_free(char **result, int i);
int		spell_count(char *str, char c, int *pos);
int		ft_countword(char *str, char c);
char	**q_split(char *str, char c);
void	ctrl_d(void);
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc(size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);

void	execute(t_token *token, char **cnvp, char *begin, int tcnt);
int		one_inbuilt(t_token *token, char **cnvp);
void	match_cmd(t_token *token, int *cmd);
void	execute_cmd(t_token *token, char **cnvp, int cmd);
int		open_infile(t_token *token, int idx);
int		open_outfile(t_token *token, int idx);
int		cnt_file(char **file);
void	free_close(t_token *token, int *fd, int idx);
int		in_last(t_token *token, int idx, int last_fd);
void	and_more(t_token *token, char **cnvp, int tcnt);
void	Parallelism(t_token *token, char **cnvp, int idx, int last);
void	idx_first(t_token *token, char **cnvp, int idx);
void	idx_last(t_token *token, char **cnvp, int idx);
void	idx_middle(t_token *token, char **cnvp, int idx);
void	dup_stdin(t_token *token, int idx, int fd);
void	dup_stdout(int fd);
void	begin_pipe(int *fd);
void	end_pipe(int *fd);
int		execute_more_cmd(t_token *token, char **cnvp, int idx);
int		path_cmd(t_token *token, char **cnvp, int idx);
int		tav_cmd(t_token *token, int idx);
int		full_path_cmd(t_token *token, int idx, char **cnvp);
char	**match_path(char **cnvp);
void	execute_execve(t_token *token, int idx, char **cnvp);
int		run_execve(t_token *token, int idx, char **cnvp);
void	output_error(char *tav, char *error);
void	output_perror(char *str);
void	sig_wait(void);
void	wait_fork(void);
void	free_var(char *tmp, char **path, t_token *token, int idx);
void	free_path(char **path);
int		free_return(char *tmp, char **path);
void	free_token(t_token *token, char *begin, int tcnt);
void	free_single(t_token *token, int idx);
void	free_double(t_token *token, int idx);
void	free_cnvp(char **cnvp, int flg);
void	free_infile(t_token *token, int idx);
void	free_outfile(t_token *token, int idx);
void	free_arr(t_token *token, int idx);
void	free_tav(t_token *token, int idx);
void	free_here_doc(t_token *token, int idx);

int		cd_execute(t_token token, char **cnvp);
void	match_pwd(char **cnvp, char *pwd, char *oldpwd);
char	*match_home(char **cnvp);
int		change_dir(t_token token, char *home);
int		chdir_home(char *home);
int		chdir_other(t_token token);
void	change_pwd(char *pwd, char **cnvp);
void	change_oldpwd(char *oldpwd, char **cnvp, char *path);
int		echo_output(t_token token);
int		exist_tav(t_token token);
int		output_echo(t_token token, int *i);
int		env_output(char **cnvp);
int		existence_of_equal(char *cnvp);
int		exit_output(t_token token);
int		check_num(char *tav);
void	error_output(char *tav);
int		export_execute(t_token token, char **cnvp, int flg);
char	**env_dup(char **cnvp);
void	env_sort(char **env);
void	export_output(char **env);
int		env_free(char **env, int flg);
int		not_equal(char *env);
void	is_equal(char **env, int i, int j, int flg);
int		match_cnvp(char *tav, char **cnvp);
void	env_add(char *tav, char **cnvp);
int		pwd_output(void);
int		unset_output(t_token token, char **cnvp);
int		exist_in_env(t_token token, char **cnvp, int idx);

int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);
void	check_status(int status, t_token *token, \
	t_heredoc *hdoc, int token_cnt);
void	print_error(char *str);
void	check_ac(int ac);
int		find_dollar_ques(char *str);
char	*dollar_ques(char *str);

#endif