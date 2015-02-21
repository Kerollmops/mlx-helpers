/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 18:38:51 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 19:07:20 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_helpers.h"

void			swap(void *a, void *b)
{
	void		*tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int				int_part(double a)
{
	return (a);
}

double			floor_part(double a)
{
	return (a - int_part(a));
}

double			reverse_floor_part(double a)
{
	return (1.0 - floor_part(a));
}

