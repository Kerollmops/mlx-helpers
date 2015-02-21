/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 23:23:33 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 00:11:37 by crenault         ###   ########.fr       */
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
	return (sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y))));
}
