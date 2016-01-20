/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:12:56 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/29 19:56:41 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		ft_cd(char *line, t_env *env)
{
	char	**cdtab;
	char	*newpath;
	char	*tmp;

	tmp = NULL;
	cdtab = ft_strsplit(line, ' ');
	tmp = getcwd(tmp, MAXPATHLEN);
	newpath = ft_my_join(tmp, "/");
	newpath = ft_my_join(newpath, cdtab[1]);
	if (access(newpath, 0) == F_OK && chdir(cdtab[1]) == 0)
	{
		if (ft_replace_line_env(env, "OLDPWD", tmp) == 0)
			ft_add_line(env, "OLDPWD", tmp);
		if (ft_replace_line_env(env, "PWD", getcwd(tmp, MAXPATHLEN)) == 0)
			ft_add_line(env, "PWD", getcwd(tmp, MAXPATHLEN));
		env->oldpwd = tmp;
	}
	else
		ft_cd_bis(tmp, cdtab);
	free(newpath);
}

void		ft_cd_minus_bis(char *tmp, char *tmp2, char **cdtab)
{
	tmp2 = ft_my_join(tmp, "/");
	tmp2 = ft_my_join(tmp2, cdtab[2]);
	if (access(tmp2, 0) == F_OK)
		ft_error_cd(cdtab[2], 2);
	else
		ft_error_cd(cdtab[2], 1);
}

void		ft_cd_minus(t_env *env, char *line)
{
	char	*tmp;
	char	*tmp2;
	char	**cdtab;

	tmp2 = NULL;
	cdtab = ft_strsplit(line, ' ');
	if (!cdtab)
		return ;
	tmp = env->oldpwd;
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (!cdtab[2] && chdir(tmp) == 0)
	{
		if (ft_replace_line_env(env, "PWD", tmp) == 0)
			ft_add_line(env, "PWD", tmp);
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		env->oldpwd = tmp2;
	}
	else
		ft_cd_minus_bis(tmp, tmp2, cdtab);
}

void		ft_cd_home(t_env *env)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = env->home;
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (chdir(tmp) == 0)
	{
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		if (ft_replace_line_env(env, "PWD", tmp) == 0)
			ft_add_line(env, "PWD", getcwd(tmp2, MAXPATHLEN));
		env->oldpwd = tmp2;
	}
}

void		ft_cd_tilde(t_env *env, char **cdtab)
{
	char	*newpath;
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = ft_my_join(env->home, "");
	newpath = ft_my_join(tmp, cdtab[1] + 1);
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (access(newpath, 0) == F_OK && chdir(newpath) == 0)
	{
		if (ft_replace_line_env(env, "PWD", newpath) == 0)
			ft_add_line(env, "PWD", newpath);
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		env->oldpwd = tmp2;
	}
	else
	{
		tmp = ft_my_join(tmp, "/");
		tmp = ft_my_join(tmp, cdtab[1] + 1);
		if (access(tmp, 0) == F_OK)
			ft_error_cd(cdtab[1], 2);
		else
			ft_error_cd(cdtab[1], 1);
	}
}
