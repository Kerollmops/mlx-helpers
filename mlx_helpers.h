/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:23:30 by crenault          #+#    #+#             */
/*   Updated: 2015/02/20 23:34:09 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_HELPERS_H
# define MLX_HELPERS_H

# include "structs.h"

#pragma message("delete printf")
# include <stdio.h>

#pragma message("delete mlx include")
# include <mlx.h>

#pragma message("to delete libft ???")
# include "libft/includes/libft.h"

/*
**		POSITION
**
** position/basics.c
*/
t_pos			get_new_pos(int x, int y);

/*
**		COLOR
**
** color/basics.c
*/
t_color			get_new_color(uchar r, uchar g, uchar b);
#pragma message("better add color in place of rgb ?")
void			add_color(uchar r, uchar g, uchar b, t_color *out);
void			sub_color(uchar r, uchar g, uchar b, t_color *out);
t_color			color_hexa(int hexa);

/*
** color/advanced.c
*/
t_color			get_scalar(t_color a, t_color b, double ratio);
t_gradient		get_new_gradient(double min, double max, t_color start,
									t_color stop);
void			add_gradient_color(t_gradient const *grad, t_list **lst);
t_color			get_gradient_color(t_list *lst, double ratio);

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

/*
**		LINES
**
** line/basics.c
**
** *_aa_* means "antialised", and slow :)
*/
void			draw_line(t_image *image, t_pos a, t_pos b, t_color color);
void			draw_line_aa(t_image *image, t_pos a, t_pos b, t_color color);
void			draw_line_gradient();
void			draw_line_aa_gradient();

/*
** 		HAPES
*/

#endif
