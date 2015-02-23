/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:54:07 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:38 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec2	*mul2f(t_vec2 *vec1, float value)
{
	vec1->x *= value;
	vec1->y *= value;
	return (vec1);
}

t_vec2	*mul2v(t_vec2 *vec1, t_vec2 *vec2)
{
	vec1->x *= vec2->x;
	vec1->y *= vec2->y;
	return (vec1);
}
