/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:16:06 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/16 16:17:44 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		ft_putendl_color_fd(char *color, char *str, int fd)
{
	char	*end;

	end = "\033[0m";
	write(fd, color, ft_strlen(color));
	write(fd, str, ft_strlen(str));
	write(fd, end, ft_strlen(end));
	write(fd, "\n", 1);
}

void		ft_putchar_color_fd(char *color, char c, int fd)
{
	char	*end;

	end = "\033[0m";
	write(fd, color, ft_strlen(color));
	write(fd, &c, 1);
	write(fd, end, ft_strlen(end));
}

void		ft_putstr_color_fd(char *color, char *str, int fd)
{
	char	*end;

	end = "\033[0m";
	write(fd, color, ft_strlen(color));
	write(fd, str, ft_strlen(str));
	write(fd, end, ft_strlen(end));
}

char		*ft_strtri(char const *s)
{
	int		i;
	int		j;
	int		len;
	int		size;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	size = len - i;
	if (size < 0)
		size = 0;
	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	while (i <= len)
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}

char		*ft_my_join(char const *s1, char const *s2)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	tmp = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	j = 0;
	if (!tmp)
		return (NULL);
	while (s1[j] && j <= len && i <= len)
		tmp[i++] = s1[j++];
	j = 0;
	while (s2[j] && j <= len && i <= len)
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}
