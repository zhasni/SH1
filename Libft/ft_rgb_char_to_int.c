/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhasni <zhasni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 15:10:36 by zhasni            #+#    #+#             */
/*   Updated: 2014/12/30 17:37:50 by zhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_c_ti(unsigned char r, unsigned char g, unsigned char b)
{
	int		new;

	new = 0;
	new += ((b << 16) + (g << 8) + r);
	return (new);
}
