/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 16:29:18 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:35 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec3	*add3f(t_vec3 *vec1, float value)
{
	vec1->x += value;
	vec1->y += value;
	vec1->z += value;
	return (vec1);
}

t_vec3	*add3v(t_vec3 *vec1, t_vec3 *vec2)
{
	vec1->x += vec2->x;
	vec1->y += vec2->y;
	vec1->z += vec2->z;
	return (vec1);
}
