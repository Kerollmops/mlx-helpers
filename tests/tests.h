/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 11:00:57 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 19:02:19 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "../mlx_helpers.h"

/*
**		LINE
**
** line/basics.c
*/
void				draw_unicolor_line(t_image *image);
void				draw_gradient_line(t_image *image);
void				draw_multicolor_line(t_image *image);
/*
** line/advanced.c
*/
void				draw_aa_unicolor_line(t_image *image);
void				draw_aa_gradient_line(t_image *image);
void				draw_aa_multicolor_line(t_image *image);

/*
**		IMAGE
**
** image/basics.c
*/
void				draw_pixel_5_5(t_image *image);
void				print_pixel_5_5(t_image *image);
void				draw_pixel_5_10(t_image *image);

#endif
