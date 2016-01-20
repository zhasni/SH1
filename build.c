/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:03:27 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/16 16:23:38 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		ft_exit(char *s)
{
	if (!s)
		exit (0);
	exit(ft_atoi(s));
	return (0);
}

int		ft_check_cd(char *line, t_env *env)
{
	char	**cdtab;

	cdtab = ft_strsplit(line, ' ');
	if (ft_strcmp(line, "cd") == 0)
		ft_cd_home(env);
	else if (cdtab[1][0] == '-')
		ft_cd_minus(env, line);
	else if (cdtab[1][0] == '~')
		ft_cd_tilde(env, cdtab);
	else if (cdtab[0] && cdtab[1])
		ft_cd(line, env);
	return (0);
}

int		ft_env(t_env *env, char **cmd)
{
	int		i;

	i = 0;
	if (cmd[0] && cmd[1])
	{
		ft_error(cmd[1]);
		return (0);
	}
	while (env->bkp[i])
	{
		ft_putstr_color_fd("\033[0;30m", "MY ENV = ", 1);
		ft_putstr_color_fd("\033[0;33m", env->bkp[i], 1);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int		ft_setenv(char *line, t_env *env)
{
	char	**tmp;
	int		ret;
	int		len;

	ret = 0;
	tmp = ft_strsplit(line, ' ');
	if (!tmp[1])
	{
		ft_env(env, tmp);
		return (0);
	}
	len = ft_tablen(tmp);
	if (!tmp[2])
		tmp[2] = "";
	ret = ft_check_line_env(env, tmp[1]);
	if (ft_strcmp(tmp[1], "PATH") == 0)
		ft_error_setenv(2);
	else if (ret > 0 && len <= 3)
		ft_replace_line_env(env, tmp[1], tmp[2]);
	else if (ret == 0 && len <= 3)
		ft_add_line(env, tmp[1], tmp[2]);
	else
		ft_error_setenv(1);
	return (0);
}

int		ft_unsetenv(char *line, t_env *env)
{
	int		ret;
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	if (!tmp || !tmp[0] || !tmp[1])
	{
		ft_error_setenv(0);
		return (0);
	}
	ret = ft_check_line_env(env, tmp[1]);
	if (ret > 0)
	{
		ft_delete_line(env, tmp[1]);
		ft_resize_tab(env);
	}
	else
		ft_error_setenv(4);
	return (0);
}
