/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3f_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:52:58 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:33 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec3	*pow3f(t_vec3 *vec1, float value)
{
	vec1->x = pow(vec1->x, value);
	vec1->y = pow(vec1->y, value);
	vec1->z = pow(vec1->z, value);
	return (vec1);
}

t_vec3	*rt3(t_vec3 *vec1)
{
	return (mul3v(vec1, vec1));
}
