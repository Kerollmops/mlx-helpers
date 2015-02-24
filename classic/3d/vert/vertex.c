/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 10:26:16 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/24 10:25:56 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../mlx_helpers.h"

t_vert		*new_vertex3f(float x, float y, float z)
{
	t_vert	*vertex;

	if ((vertex = (t_vert *)ft_memalloc(sizeof(t_vert))) == NULL)
		return (NULL);
	vertex->pos.x = x;
	vertex->pos.y = y;
	vertex->pos.z = z;
	vertex->color.x = 0xFF;
	vertex->color.y = 0xFF;
	vertex->color.z = 0xFF;
	return (vertex);
}

t_vert		*new_vertexp(t_vec3f pos)
{
	t_vert	*vertex;

	if ((vertex = (t_vert *)ft_memalloc(sizeof(t_vert))) == NULL)
		return (NULL);
	vertex->pos.x = pos.x;
	vertex->pos.y = pos.y;
	vertex->pos.z = pos.z;
	vertex->color.x = 0xFF;
	vertex->color.y = 0xFF;
	vertex->color.z = 0xFF;
	return (vertex);
}

t_vert		*new_vertexpc(t_vec3f pos, t_vec3f color)
{
	t_vert	*vertex;

	if ((vertex = (t_vert *)ft_memalloc(sizeof(t_vert))) == NULL)
		return (NULL);
	vertex->pos.x = pos.x;
	vertex->pos.y = pos.y;
	vertex->pos.z = pos.z;
	vertex->color.x = color.x;
	vertex->color.y = color.y;
	vertex->color.z = color.z;
	return (vertex);
}
