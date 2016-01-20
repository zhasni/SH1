/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:18:17 by zhasni            #+#    #+#             */
/*   Updated: 2015/02/03 14:17:25 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		handle_signal(int signo)
{
	signo++;
	ft_putstr_color_fd("\033[0;34m", "\n$> ", 1);
}

int			ft_tablen(char **tab)
{
	int		i;

	i = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		len_s;
	char		*tmp;

	i = 0;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start + len > len_s + 1)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	if (i == len)
		return (tmp);
	return (NULL);
}

char		*ft_epur_str(char *src)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[i])
	{
		if ((src[i] == ' ' || src[i] == '	') && src[i])
		{
			i++;
			if ((tmp[j - 1] > 32 && tmp[j - 1] < 127) && (src[i] > 32 && src[i]
						< 127))
				tmp[j++] = ' ';
			continue ;
		}
		if (src[i] > 32 && src[i] < 127)
			tmp[j++] = src[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void		ft_cd_slash(t_env *env, char *arg)
{
	char	*tmp2;

	tmp2 = NULL;
	tmp2 = getcwd(tmp2, MAXPATHLEN);
	if (access(arg, 0) == F_OK && chdir(arg) == 0)
	{
		if (ft_replace_line_env(env, "PWD", arg) == 0)
			ft_add_line(env, "PWD", arg);
		if (ft_replace_line_env(env, "OLDPWD", tmp2) == 0)
			ft_add_line(env, "OLDPWD", tmp2);
		env->oldpwd = tmp2;
	}
	else
		ft_error_cd(arg, 2);
}
