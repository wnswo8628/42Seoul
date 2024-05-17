/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jugwak <jugwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:56:53 by jugwak            #+#    #+#             */
/*   Updated: 2023/05/13 21:29:37 by jugwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str)
{
	printf("%s\n", str);
	g_status = 1;
	exit(-1);
}

char	**set_main(int ac, char **av, struct termios *term, char **env)
{
	char	**copy_env;

	copy_env = env_dup(env);
	tcgetattr(STDIN_FILENO, term);
	term->c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, term);
	ctl_signal(0, 0);
	(void)ac;
	(void)av;
	return (copy_env);
}

void	check_ac(int ac)
{
	if (ac != 1)
		print_error("[Error]argument error");
}

int	find_dollar_ques(char *str)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] == '?')
		{
			pos = i + 1;
			break ;
		}
		i++;
	}
	return (pos);
}

char	*dollar_ques(char *str)
{
	char	*a;
	char	*b;
	char	*result;
	int		pos;

	pos = 0;
	if (!ft_strncmp(str, "$?", 3) || !ft_strncmp(str, "?", 2))
	{
		ft_free(str);
		return (ft_itoa(g_status));
	}
	else
	{
		pos = find_dollar_ques(str);
		a = ft_itoa(g_status);
		b = ft_substr(str, pos + 1, ft_strlen(str));
		result = ft_strjoin(a, b);
		free(a);
		free(b);
		free(str);
	}
	return (result);
}
