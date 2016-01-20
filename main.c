/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:03:02 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/27 10:45:55 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int			ft_check_slash(t_env *env, char *line)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = "";
	tmp2 = NULL;
	if (line[0] == '/')
	{
		env->arg = ft_strsplit(line, ' ');
		while (env->arg[i])
		{
			env->arg[i] = ft_strtri(env->arg[i]);
			i++;
		}
		return (1);
	}
	else if ((line[0] == '.' && line[1] == '/'))
	{
		line = ft_my_join(tmp, line + 1);
		line = ft_my_join(getcwd(tmp2, MAXPATHLEN), line);
		env->arg = ft_strsplit(line, ' ');
		return (1);
	}
	return (0);
}

char		*ft_check_first_char(t_env *env, char *line)
{
	char	**tmp;
	char	*str;

	tmp = ft_strsplit(line, ' ');
	if (!tmp || !tmp[1])
		return (line);
	if (ft_strcmp(tmp[0], "ls") == 0 && tmp[1][0] == '~')
	{
		str = env->home;
		tmp[0] = ft_my_join(tmp[0], " ");
		tmp[0] = ft_my_join(tmp[0], str);
		line = ft_my_join(tmp[0], tmp[1] + 1);
	}
	return (line);
}

void		ft_fork(t_env *env, char **envp, char *line)
{
	pid_t	pid;
	int		a;

	if (ft_check_slash(env, line) == 0)
		ft_check_path(env, line);
	pid = fork();
	if (pid == 0)
	{
		if (execve(env->arg[0], env->arg, envp) == -1)
			ft_error(line);
		exit(0);
	}
	else
		waitpid(pid, &a, 0);
	ft_putstr_color_fd("\033[0;32m", "\b\b\b$> ", 1);
	free(line);
}

void		ft_prompt(t_env *env, char **envp)
{
	char	*line;

	signal(SIGINT, handle_signal);
	ft_putstr_color_fd("\033[0;33m", "$> ", 1);
	while (get_next_line(0, &line) == 1)
	{
		line = ft_epur_str(line);
		line = ft_strtri(line);
		line = ft_check_first_char(env, line);
		if (ft_check_build(line, env) == 0)
		{
			ft_putstr_color_fd("\033[0;31m", "$> ", 1);
			continue ;
		}
		ft_fork(env, envp, line);
	}
}

int			main(int ac, char **av, char **envp)
{
	t_env	env;
	int		i;

	i = 0;
	(void)av;
	if (!envp || !*envp)
		return (-1);
	ft_get_env(&env, envp);
	env.path = ft_strsplit(*envp, '=');
	if (!env.path[1])
		return (-1);
	env.path = ft_strsplit(ft_get_line_env(&env, "PATH"), ':');
	env.home = ft_get_line_env(&env, "HOME");
	while (env.path[i])
	{
		env.path[i] = ft_my_join(env.path[i], "/");
		i++;
	}
	if (ac == 1)
		ft_prompt(&env, envp);
	return (0);
}
