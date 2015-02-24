/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 11:00:57 by crenault          #+#    #+#             */
/*   Updated: 2015/02/24 13:51:09 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "../../classic_mlx_helpers.h"

/*
**		LINE
**
** line/basics.c
*/
void				test_draw_unicolor_line(t_image *image);
void				test_draw_gradient_line(t_image *image);
void				test_draw_multicolor_line(t_image *image);
/*
** line/advanced.c
*/
void				test_draw_aa_unicolor_line(t_image *image);
void				test_draw_aa_gradient_line(t_image *image);
void				test_draw_aa_multicolor_line(t_image *image);
/*
** line/complex.c
*/
void				test_draw_bezier_unicolor(t_image *image);
void				test_draw_bezier_gradient(t_image *image);
void				test_draw_bezier_multicolor(t_image *image);
void				test_draw_bezier_aa_unicolor(t_image *image);
void				test_draw_bezier_aa_gradient(t_image *image);
void				test_draw_bezier_aa_multicolor(t_image *image);


/*
**		IMAGE
**
** image/basics.c
*/
void				test_draw_pixel(t_image *image);
void				test_print_pixel(t_image *image);
void				test_draw_pixel_2(t_image *image);

/*
**		TEXT
**
** text/basics.c
*/
void				test_display_text(t_image *image);

#endif
