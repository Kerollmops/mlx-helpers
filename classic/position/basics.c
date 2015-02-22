/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 23:23:33 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 12:12:25 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"
#include <math.h>

t_pos			get_new_pos(int x, int y)
{
	t_pos		position;

	position.x = x;
	position.y = y;
	return (position);
}

double			get_pos_distance(t_pos a, t_pos b)
{
	//return (get_pos_fdistance(get_new_fpos(a.x, a.y), get_new_fpos(b.x, b.y)));
	return (sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y))));
}

t_fpos		get_new_fpos(float x, float y)
{
	t_fpos	position;

	position.x = x;
	position.y = y;
	return (position);
}

double			get_pos_fdistance(t_fpos a, t_fpos b)
{
	return (sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y))));
}
