/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 16:01:39 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 22:05:35 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

void				draw_aa_unicolor_line(t_image *image)
{
	draw_line_aa(	image,
					get_new_pos(10, 80), get_new_pos(70, 140),
					get_new_color(255, 255, 255, 1.0));	// white
}

void				draw_aa_gradient_line(t_image *image)
{
	(void)image;
}

void				draw_aa_multicolor_line(t_image *image)
{
	(void)image;
}
