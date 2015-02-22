/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:38:51 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 00:12:38 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"
#include <math.h>

void			swap_int(int *a, int *b)
{
	int			tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				int_part(double a)
{
	return (a);
}

double			floor_part(double x)
{
	if (x < 0)
        return 1 - (x - floor(x));
    return x - floor(x);
}

double			reverse_floor_part(double a)
{
	return (1.0 - floor_part(a));
}

