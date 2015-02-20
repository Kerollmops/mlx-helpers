/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:22:50 by crenault          #+#    #+#             */
/*   Updated: 2015/02/20 23:36:01 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_helpers.h"

int				main(int argc, char const **argv)
{
	void		*mlx;
	void		*win;
	t_image		image;

	if ((mlx = mlx_init()) == 0)
		return (1);

	// get new image
	image = get_new_image(mlx, 100, 100);

	/*
	// put pixel
	t_color		add;
	add = get_new_color(250, 125, 0);
	put_pixel_image(&image, get_new_pos(20, 20), add);*/

	/*
	// get a pixel from image and change it, put it
	t_color		ret;
	ret = get_pixel_image(&image, get_new_pos(20, 20));
	printf("%d, %d, %d\n", ret.r, ret.g, ret.b);
	add_color(0, 255, 0, &ret);
	sub_color(255, 0, 0, &ret);
	put_pixel_image(&image, get_new_pos(20, 25), ret);*/


	// put line unicolor
	draw_line(	&image,
				get_new_pos(0, 0), get_new_pos(99, 99),
				get_new_color(255, 255, 255));

	//
	win = mlx_new_window(mlx, 100, 100, (char *)"salut");
	mlx_put_image_to_window(mlx, win, image.ptr, 0, 0);

	//
	mlx_loop(mlx);

	(void)argc;
	(void)argv;
	return (0);
}
