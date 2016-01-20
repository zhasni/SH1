/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:14:28 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/07 12:15:33 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	if (!tab || !*tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}
