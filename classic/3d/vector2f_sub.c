/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:53:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:36 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec2	*sub2f(t_vec2 *vec1, float value)
{
	vec1->x -= value;
	vec1->y -= value;
	return (vec1);
}

t_vec2	*sub2v(t_vec2 *vec1, t_vec2 *vec2)
{
	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
	return (vec1);
}

t_vec2	*inv2(t_vec2 *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	return (vec);
}
