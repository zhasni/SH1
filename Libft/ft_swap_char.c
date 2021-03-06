/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 17:55:22 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/29 18:18:34 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_char(char *a, char *b)
{
	char	tmp;

	if (!a || !b)
		return ;
	tmp = *b;
	*b = *a;
	*a = tmp;
}
