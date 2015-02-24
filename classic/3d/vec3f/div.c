/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:30:46 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/24 10:25:59 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../mlx_helpers.h"

t_vec3f	*div3f(t_vec3f *vec1, float value)
{
	vec1->x /= value;
	vec1->y /= value;
	vec1->z /= value;
	return (vec1);
}

t_vec3f	*div3v(t_vec3f *vec1, t_vec3f *vec2)
{
	vec1->x /= vec2->x;
	vec1->y /= vec2->y;
	vec1->z /= vec2->z;
	return (vec1);
}
