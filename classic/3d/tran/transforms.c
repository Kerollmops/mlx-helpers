/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transforms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 18:05:39 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/24 10:26:00 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../mlx_helpers.h"

t_tran		*new_transform(void)
{
	t_tran		*t;

	if ((t = (t_tran *)ft_memalloc(sizeof(t_tran))) == NULL)
		return (NULL);
	t->pos.x = 0;
	t->pos.y = 0;
	t->pos.z = 0;
	t->rot.x = 0;
	t->rot.y = 0;
	t->rot.z = 0;
	t->rot.w = 1;
	t->scale.x = 1;
	t->scale.y = 1;
	t->scale.z = 1;
	return (t);
}

t_vec3f		*transform(t_vec3f *v, t_mat4 *m)
{
	t_vec3f	*res;
	float	x;
	float	y;
	float	z;

	if ((res = (t_vec3f *)ft_memalloc(sizeof(t_vec3f))) == NULL)
		return (NULL);
	x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z + m->m[0][3];
	y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z + m->m[1][3];
	z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z + m->m[2][3];
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}

t_mat4		*get_transforms(t_tran *t)
{
	t_mat4	*translation;
	t_mat4	*rotation;
	t_mat4	*scale;
	t_mat4	*tmp;
	t_mat4	*tmp2;

	translation = init_translation(&t->pos);
	rotation = to_rotation_matrix(&t->rot);
	scale = init_scale(t->scale.x, t->scale.y, t->scale.z);
	tmp = mul4m(rotation, scale);
	ft_memdel((void **)&rotation);
	ft_memdel((void **)&scale);
	tmp2 = mul4m(translation, tmp);
	ft_memdel((void **)&translation);
	ft_memdel((void **)&tmp);
	return (tmp2);
}
