/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:23:30 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 14:05:44 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H

# define MLX_HELPERS_DEBUG 1

# include "structs.h"
# include <mlx.h>

#pragma message("delete printf")
# include <stdio.h>

#pragma message("to delete math.h ???")
# include <math.h>

#pragma message("to delete libft ???")
# include "libft/includes/libft.h"

#pragma message("norme antialised lines")
#pragma message("manage bezier curves + antialiased")
#pragma message("create classic and boosted lib")
#pragma message("+ header for each (classic and boosted)")

/*
** basics / advanced / complex / extra_complex / hardcore
**
** http://en.cppreference.com/w/c/language/operator_precedence
** http://goo.gl/1iF2bX
**
** font type (.ttf)
** http://stevehanov.ca/blog/index.php?id=143
*/

/*
**		HELPERS
**
** helpers/basics.c
*/
void			swap_int(int *a, int *b);

#pragma message("change folder")
int				int_part(double a);
double			floor_part(double a);
double			reverse_floor_part(double a);

/*
**		POSITION
**
** position/basics.c
*/
t_pos			get_new_pos(int x, int y);
double			get_pos_distance(t_pos a, t_pos b);
t_fpos			get_new_fpos(float x, float y);
double			get_pos_fdistance(t_fpos a, t_fpos b);
/*
** position/advanced.c
*/
t_fpos			lerp(t_fpos a, t_fpos b, const double t);
void			add_position(t_fpos pos, t_list **lst);
t_list			*get_pos_node(t_list *lst, size_t n);
void			del_pos_list(t_list **lst);

/*
**		COLOR
**
** color/basics.c
*/
#pragma message("limit color 255")
t_color			get_new_color(float r, float g, float b, float alpha);
t_color			add_color(t_color in, t_color add);
t_color			sub_color(t_color in, t_color add);
t_color			color_hexa(int hexa);
/*
** color/advanced.c
*/
t_color			get_scalar(t_color a, t_color b, double ratio);
t_gradient		get_new_gradient(double min, double max, t_color start,
									t_color stop);
void			add_gradient_color(t_gradient grad, t_list **lst);
t_color			get_gradient_color(t_list *lst, double ratio);
void			del_gradient_list(t_list **lst);
/*
** color/complex.c
*/
//

/*
**		IMAGE
**
** image/basics.c
*/
t_image			get_new_image(void *mlx, int width, int height);
void			put_pixel_image(t_image *image, t_pos pos, t_color color);
t_color			get_pixel_image(t_image *image, t_pos pos);
void			clear_image(t_image *image);

/*
**		LINES
**
** line/basics.c
**
** _aa_ means "antialised"
*/
void			draw_line(t_image *image, t_pos a, t_pos b, t_color color);
void			draw_line_gradient(t_image *img, t_pos a, t_pos b, t_list *lst);
/*
** line/advanced.c
*/
void			draw_line_aa(t_image *image, t_pos a, t_pos b, t_color color);
void			draw_line_aa_gradient(t_image *i, t_pos a, t_pos b, t_list *l);
/*
** line/complex.c
*/
void			draw_bezier_func(t_image *image, t_list *points, t_list *grads,
									void (*f)(t_image*, t_pos, t_pos, t_color));
void			draw_bezier(t_image *image, t_list *points, t_color color);
void			draw_bezier_gradient(t_image *image, t_list *points, t_list *g);
void			draw_bezier_aa(t_image *image, t_list *points, t_color c);
void			draw_bezier_aa_gradient(t_image *img, t_list *pots, t_list *g);

/*
**		3D
**
**	3d/vector2f.c
*/
t_vec2			*new_vector2f(float x, float y);
float			length2(t_vec2 *vec);
float			dot2(t_vec2 *vec1, t_vec2 *vec2);
float			cross2(t_vec2 *vec1, t_vec2 *vec2);
t_vec2			*normalized2(t_vec2 *vec);
t_vec2			*inv2(t_vec2 *vec);
t_vec2			*add2v(t_vec2 *vec1, t_vec2 *vec2);
t_vec2			*sub2v(t_vec2 *vec1, t_vec2 *vec2);
t_vec2			*mul2v(t_vec2 *vec1, t_vec2 *vec2);
t_vec2			*div2v(t_vec2 *vec1, t_vec2 *vec2);
t_vec2			*add2f(t_vec2 *vec1, float value);
t_vec2			*sub2f(t_vec2 *vec1, float value);
t_vec2			*mul2f(t_vec2 *vec1, float value);
t_vec2			*div2f(t_vec2 *vec1, float value);
t_vec2			*pow2f(t_vec2 *vec1, float value);
t_vec2			*rt2(t_vec2 *vec1);
t_vec2			*rotate2(t_vec2 *vec, float angle);
float			get_value2(t_vec2 *vec);

/*
**	3d/vector3f.c
*/
t_vec3			*new_vector3f(float x, float y, float z);
float			length3(t_vec3 *vec);
float			dot3(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*cross3(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*normalized3(t_vec3 *vec);
t_vec3			*inv3(t_vec3 *vec);
t_vec3			*add3v(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*sub3v(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*mul3v(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*div3v(t_vec3 *vec1, t_vec3 *vec2);
t_vec3			*add3f(t_vec3 *vec1, float value);
t_vec3			*sub3f(t_vec3 *vec1, float value);
t_vec3			*mul3f(t_vec3 *vec1, float value);
t_vec3			*div3f(t_vec3 *vec1, float value);
t_vec3			*pow3f(t_vec3 *vec1, float value);
t_vec3			*rt3(t_vec3 *vec1);
t_vec3			*rotate3(t_vec3 *vec, t_vec3 *axis, float angle);
t_vec3			*rotate3q(t_vec3 *vec, t_quat *rotation);
float			get_value3(t_vec3 *vec);

/*
**	3d/matrix4f.c
*/
t_mat4			*new_matrix4();
t_mat4			*mul4m(t_mat4 *m, t_mat4 *r);
t_mat4			*init_rotation3f(float x, float y, float z);
t_mat4			*init_translation(t_vec3 *vec);
t_mat4			*init_rotation3v(t_vec3 *f, t_vec3 *u, t_vec3 *r);
t_mat4			*init_scale(float x, float y, float z);
t_mat4			*init_perspective(float a, float b, float c, float d);

/*
**	3d/quaternion.c
*/
t_quat			*new_quaternion4f(float x, float y, float z, float w);
t_quat			*new_quaternion4vf(t_vec3 *axis, float angle);
float			length4(t_quat *q);
t_quat			*normalized4(t_quat *q);
t_quat			*conjugate4(t_quat *q);
t_mat4			*to_rotation_matrix(t_quat *q);
t_quat			*mul4q(t_quat *q, t_quat *r);
t_quat			*mul4v(t_quat *q, t_vec3 *r);

/*
**	3d/vertex.c
*/
t_vert			*new_vertex3f(float x, float y, float z);
t_vert			*new_vertexp(t_vec3 pos);
t_vert			*new_vertexpc(t_vec3 pos, t_vec3 color);

/*
**	3d/transforms.c
*/
t_tran			*new_transform(void);
t_vec3			*transform(t_vec3 *v, t_mat4 *m);
t_mat4			*get_transforms(t_tran *t);

/*
**	3d/utils.c
*/
float			to_radians(float angle);
float			rt(float val);

/*
**		TEXT
*/
#pragma message("text todo")

/*
** 		SHAPES
*/
#pragma message("shapes todo")

#endif
