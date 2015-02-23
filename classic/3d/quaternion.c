/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 13:09:33 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:46 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_quat	*new_quaternion4f(float x, float y, float z, float w)
{
	t_quat	*q;

	if ((q = (t_quat *)ft_memalloc(sizeof(t_quat))) == NULL)
		return (NULL);
	q->x = x;
	q->y = y;
	q->z = z;
	q->w = w;
	return (q);
}

t_quat	*new_quaternion4vf(t_vec3 *axis, float angle)
{
	t_quat			*q;
	float			sin_half_angle;
	float			cos_half_angle;

	if ((q = (t_quat *)ft_memalloc(sizeof(t_quat))) == NULL)
		return (NULL);
	sin_half_angle = (float)sin(to_radians(angle) / 2);
	cos_half_angle = (float)cos(to_radians(angle) / 2);
	q->x = axis->x * sin_half_angle;
	q->y = axis->y * sin_half_angle;
	q->z = axis->z * sin_half_angle;
	q->w = cos_half_angle;
	return (q);
}

float	length4(t_quat *q)
{
	return ((float)sqrt(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w));
}

t_quat	*normalized4(t_quat *q)
{
	float	l;

	l = length4(q);
	q->x /= l;
	q->y /= l;
	q->z /= l;
	q->w /= l;
	return (q);
}

t_quat	*conjugate4(t_quat *q)
{
	q->x = -q->x;
	q->y = -q->y;
	q->z = -q->z;
	return (q);
}
