/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:22:50 by crenault          #+#    #+#             */
/*   Updated: 2015/02/24 13:32:43 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int				main(int argc, char const **argv)
{
	static const int	width = 1280;
	static const int	height = 720;
	void				*mlx;
	void				*win;
	t_image				image;

	if ((mlx = mlx_init()) == 0)
		return (1);

	// get new image
	image = get_new_image(mlx, width, height);

	/*
	** image tests
	*/
	test_draw_pixel(&image);
	test_print_pixel(&image);
	test_draw_pixel_2(&image);

	/*
	** line tests
	*/
	test_draw_aa_unicolor_line(&image);
	test_draw_aa_gradient_line(&image);
	test_draw_aa_multicolor_line(&image);
	//
	test_draw_unicolor_line(&image);
	test_draw_gradient_line(&image);
	test_draw_multicolor_line(&image);
	//
	test_draw_bezier_unicolor(&image);
	test_draw_bezier_gradient(&image);
	test_draw_bezier_multicolor(&image);
	//
	test_draw_bezier_aa_unicolor(&image);
	test_draw_bezier_aa_gradient(&image);
	test_draw_bezier_aa_multicolor(&image);
	//
	test_display_text(&image);

	//clear_image(&image);

	//
	win = mlx_new_window(mlx, width, height, (char *)"salut");
	mlx_put_image_to_window(mlx, win, image.ptr, 0, 0);

	//
	mlx_loop(mlx);

	(void)argc;
	(void)argv;
	return (0);
}
