/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolowerstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:31:14 by zhasni            #+#    #+#             */
/*   Updated: 2015/01/16 15:31:36 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char	*ft_tolowerstr(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	str[i] = '\0';
	return (str);
}
