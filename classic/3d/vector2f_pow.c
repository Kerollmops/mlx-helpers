/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:55:57 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:37 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec2	*pow2f(t_vec2 *vec1, float value)
{
	vec1->x = pow(vec1->x, value);
	vec1->y = pow(vec1->y, value);
	return (vec1);
}

t_vec2	*rt2(t_vec2 *vec1)
{
	return (mul2v(vec1, vec1));
}
