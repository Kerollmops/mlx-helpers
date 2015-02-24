/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:38:51 by crenault          #+#    #+#             */
/*   Updated: 2015/02/24 13:52:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../classic_mlx_helpers.h"
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

