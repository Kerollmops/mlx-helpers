/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:53:30 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/24 13:53:05 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../classic_mlx_helpers.h"

t_vec2f	*sub2f(t_vec2f *vec1, float value)
{
	vec1->x -= value;
	vec1->y -= value;
	return (vec1);
}

t_vec2f	*sub2v(t_vec2f *vec1, t_vec2f *vec2)
{
	vec1->x -= vec2->x;
	vec1->y -= vec2->y;
	return (vec1);
}

t_vec2f	*inv2(t_vec2f *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	return (vec);
}
