/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2f_div.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:55:04 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:39 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_vec2	*div2f(t_vec2 *vec1, float value)
{
	vec1->x /= value;
	vec1->y /= value;
	return (vec1);
}

t_vec2	*div2v(t_vec2 *vec1, t_vec2 *vec2)
{
	vec1->x /= vec2->x;
	vec1->y /= vec2->y;
	return (vec1);
}
