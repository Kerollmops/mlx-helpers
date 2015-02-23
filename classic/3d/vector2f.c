/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:24:33 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:40 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec2	*new_vector2f(float x, float y)
{
	t_vec2 *vec;

	if ((vec = (t_vec2 *)ft_memalloc(sizeof(t_vec2))) == NULL)
		return (NULL);
	vec->x = x;
	vec->y = y;
	return (vec);
}

float	length2(t_vec2 *vec)
{
	return ((float)sqrt(vec->x * vec->x + vec->y * vec->y));
}

float	dot2(t_vec2 *vec1, t_vec2 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y);
}

float	cross2(t_vec2 *vec1, t_vec2 *vec2)
{
	return (vec1->x * vec2->y - vec1->y * vec2->x);
}

t_vec2	*normalized2(t_vec2 *vec)
{
	float	length;

	length = length2(vec);
	vec->x /= length;
	vec->y /= length;
	return (vec);
}
