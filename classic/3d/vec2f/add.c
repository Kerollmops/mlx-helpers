/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:52:40 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/24 13:53:10 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../classic_mlx_helpers.h"

t_vec2f	*add2f(t_vec2f *vec1, float value)
{
	vec1->x += value;
	vec1->y += value;
	return (vec1);
}

t_vec2f	*add2v(t_vec2f *vec1, t_vec2f *vec2)
{
	vec1->x += vec2->x;
	vec1->y += vec2->y;
	return (vec1);
}
