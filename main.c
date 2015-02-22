/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:22:50 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 00:34:39 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

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
	draw_pixel_5_5(&image);
	print_pixel_5_5(&image);
	draw_pixel_5_10(&image);

	/*
	** line tests
	*/
	draw_aa_unicolor_line(&image);
	draw_aa_gradient_line(&image);
	draw_aa_multicolor_line(&image);
	//
	draw_unicolor_line(&image);
	draw_gradient_line(&image);
	draw_multicolor_line(&image);

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
