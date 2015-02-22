/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:23:30 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 00:13:06 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H

# define MLX_HELPERS_DEBUG 1

# include "structs.h"
# include <mlx.h>

#pragma message("delete printf")
# include <stdio.h>

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
**		TEXT
*/
#pragma message("text todo")

/*
** 		SHAPES
*/
#pragma message("shapes todo")

#endif
