/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:29:23 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/16 15:30:43 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_error(char *line)
{
	char	**tmp;

	if (ft_isprint(line[0]))
	{
		tmp = ft_strsplit(line, ' ');
		ft_putstr_color_fd("\033[0;35m", "ft_minishell1 : command not found: "
			, 2);
		ft_putstr_color_fd("\033[0;36m", tmp[0], 2);
		ft_putstr_fd("\n", 2);
		free(tmp);
	}
}

void	ft_error_setenv(int n)
{
	if (n == 1)
		ft_putendl_color_fd("\033[0;37m", "setenv : Too many arguments", 2);
	else if (n == 2)
		ft_putendl_color_fd("\033[0;40m", "setenv: PATH: Permission denied",
			2);
	else if (n == 0)
		ft_putendl_color_fd("\033[0;39m", "unsetenv : Too few arguments", 2);
	else
		ft_putendl_color_fd("\033[0;41m",
			"unsetenv : Too many arguments or Permission denied", 2);
}

void	ft_error_cd_ter(char *line, int n)
{
	char	**tmp;

	if (n == 3)
	{
		if (ft_isprint(line[0]))
		{
			tmp = ft_strsplit(line, ' ');
			ft_putstr_color_fd("\033[0;47m", "cd: permission denied: ", 2);
			ft_putstr_color_fd("\033[0;46m", tmp[0], 2);
			ft_putchar_fd('\n', 2);
			free(tmp);
		}
	}
}

void	ft_error_cd_bis(char *line, int n)
{
	char	**tmp;

	if (n == 2)
	{
		if (ft_isprint(line[0]))
		{
			tmp = ft_strsplit(line, ' ');
			ft_putstr_color_fd("\033[0;42m", "cd: not a directory: ", 2);
			ft_putstr_color_fd("\033[0;43m", tmp[0], 2);
			ft_putchar_fd('\n', 2);
			free(tmp);
		}
	}
}

void	ft_error_cd(char *line, int n)
{
	char	**tmp;

	if (n == 1)
	{
		if (ft_isprint(line[0]))
		{
			tmp = ft_strsplit(line, ' ');
			ft_putstr_color_fd("\033[0;44m", "cd: no such file or directory: "
				, 2);
			ft_putstr_color_fd("\033[0;45m", tmp[0], 2);
			ft_putchar_fd('\n', 2);
			free(tmp);
		}
	}
	else if (n == 2)
		ft_error_cd_bis(line, n);
	else
		ft_error_cd_ter(line, n);
}
