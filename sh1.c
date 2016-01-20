/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:31:33 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/27 11:26:24 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*ft_check_path(t_env *env, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	line = ft_strtri(line);
	while (env->path[i])
	{
		tmp = ft_my_join(env->path[i], line);
		env->arg = ft_strsplit(tmp, ' ');
		while (env->arg[j])
		{
			env->arg[j] = ft_strtri(env->arg[j]);
			j++;
		}
		if (access(env->arg[0], 0) == F_OK)
			return (env->arg[0]);
		i++;
	}
	free(tmp);
	return (env->arg[i]);
}

int			ft_check_build(char *line, t_env *env)
{
	char	**cmd;
	char	*minmaj;
	int		i;

	i = 0;
	cmd = ft_strsplit(line, ' ');
	if (!cmd || !cmd[0])
		return (-1);
	while (cmd[i])
	{
		cmd[i] = ft_strtri(cmd[i]);
		i++;
	}
	if (ft_strcmp(cmd[0], "cd") == 0)
		return (ft_check_cd(line, env));
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (ft_setenv(line, env));
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (ft_unsetenv(line, env));
	minmaj = ft_tolowerstr(cmd[0]);
	if (ft_strcmp(minmaj, "env") == 0)
		return (ft_env(env, cmd));
	else if (ft_strcmp(cmd[0], "exit") == 0)
		ft_exit(cmd[1]);
	return (-1);
}

void		ft_get_env(t_env *env, char **envp)
{
	int		i;
	int		lentab;

	i = 0;
	lentab = ft_tablen(envp);
	if (!(env->bkp = malloc(sizeof(char *) * lentab)))
		return ;
	while (envp[i])
	{
		env->bkp[i] = ft_strdup(envp[i]);
		i++;
	}
	env->oldpwd = ft_get_line_env(env, "OLDPWD");
	return ;
}

int			ft_replace_line_env(t_env *env, char *key, char *newpath)
{
	int		index;
	int		i;
	char	*tmp;

	index = 0;
	while (env->bkp[index])
	{
		i = 0;
		while (env->bkp[i] && key[i] && key[i] == env->bkp[index][i])
			i++;
		if (env->bkp[index][i] == '=')
		{
			tmp = ft_my_join(key, "=");
			env->bkp[index] = ft_my_join(tmp, newpath);
			return (1);
		}
		index++;
	}
	return (0);
}

char		*ft_get_line_env(t_env *env, char *key)
{
	int		index;
	int		i;

	index = 0;
	while (env->bkp[index])
	{
		i = 0;
		while (env->bkp[i] && key[i] && key[i] == env->bkp[index][i])
			i++;
		if (env->bkp[index][i] == '=')
			return (&env->bkp[index][i + 1]);
		index++;
	}
	return (NULL);
}
