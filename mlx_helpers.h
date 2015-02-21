/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:23:30 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 22:06:47 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H

# define MLX_HELPER_DEBUG 1

# include "structs.h"

#pragma message("delete printf")
# include <stdio.h>

#pragma message("delete mlx include")
# include <mlx.h>

#pragma message("to delete libft ???")
# include "libft/includes/libft.h"

#pragma message("manage alpha values with coor and images")
#pragma message("create classic and boosted lib")

/*
** basics / advanced / complex / extra_complex / hardcore
**
** http://en.cppreference.com/w/c/language/operator_precedence
*/

/*
**		HELPERS
**
** helpers/basics.c
*/
void			swap(void *a, void *b);

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
t_dblpos		get_new_dbl_pos(int x, int y);
double			get_pos_dbl_distance(t_dblpos a, t_dblpos b);

/*
**		COLOR
**
** color/basics.c
*/
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
// alternative: t_image *image, int const *x, int const *y, t_color const *color
void			put_pixel_image(t_image *image, t_pos pos, t_color color);
t_color			get_pixel_image(t_image *image, t_pos pos);
void			clear_image(t_image *image);

/*
**		LINES
**
** line/basics.c
**
** *_aa_* means "antialised", and slow :)
*/
void			draw_line(t_image *image, t_pos a, t_pos b, t_color color);
void			draw_line_gradient(t_image *img, t_pos a, t_pos b, t_list *lst);

/*
** line/advanced.c
*/
void			draw_line_aa(t_image *image, t_pos a, t_pos b, t_color color);
void			draw_line_aa_gradient(t_image *i, t_pos a, t_pos b, t_list *l);

/*
**		TEXT
*/
#pragma message("text todo")

/*
** 		SHAPES
*/
#pragma message("shapes todo")

#endif
