/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:56:13 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:37 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec2	*rotate2(t_vec2 *vec, float angle)
{
	float		rad;
	float		c;
	float		s;

	rad = to_radians(angle);
	c = cos(rad);
	s = sin(rad);
	vec->x = vec->x * c - vec->y * s;
	vec->y = vec->x * s + vec->y * c;
	return (vec);
}
