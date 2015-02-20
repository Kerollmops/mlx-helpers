/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:22:50 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 00:47:20 by crenault         ###   ########.fr       */
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
				get_new_pos(10, 10), get_new_pos(10, 70),
				get_new_color(255, 255, 255));

	// put line multicolor
	t_list		*gradient_lst;
	gradient_lst = NULL;
	add_gradient_color(	get_new_gradient(0, 1,
											get_new_color(0, 0, 0),
											get_new_color(255, 255, 255)
										),
						&gradient_lst);
	draw_line_aa(	&image,
					get_new_pos(10 + 20, 10), get_new_pos(10 + 20, 70),
					gradient_lst);

	// another line
	t_list		*gradient_lst2;
	gradient_lst2 = NULL;
	add_gradient_color(	get_new_gradient(0, 0.5,
											get_new_color(0, 0, 0),
											get_new_color(255, 255, 255)
										),
						&gradient_lst2);
	add_gradient_color(	get_new_gradient(0.5, 1,
											get_new_color(255, 255, 255),
											get_new_color(0, 0, 0)
										),
						&gradient_lst2);
	draw_line_aa(	&image,
					get_new_pos(10 + 40, 10), get_new_pos(10 + 40, 70),
					gradient_lst2);

	// another another line
	t_list		*gradient_lst3;
	gradient_lst3 = NULL;
	add_gradient_color(	get_new_gradient(0, 0.5,
											get_new_color(255, 255, 255),
											get_new_color(0, 0, 0)
										),
						&gradient_lst3);
	add_gradient_color(	get_new_gradient(0.5, 1,
											get_new_color(0, 0, 0),
											get_new_color(255, 255, 255)
										),
						&gradient_lst3);
	draw_line_aa(	&image,
					get_new_pos(10 + 60, 10), get_new_pos(10 + 60, 70),
					gradient_lst3);

	// another another another line
	t_list		*gradient_lst4;
	gradient_lst4 = NULL;
	add_gradient_color(	get_new_gradient(0, 0.2,
											get_new_color(255, 0, 0),
											get_new_color(255, 255, 0)
										),
						&gradient_lst4);
	add_gradient_color(	get_new_gradient(0.2, 0.4,
											get_new_color(255, 255, 0),
											get_new_color(0, 255, 0)
										),
						&gradient_lst4);
	add_gradient_color(	get_new_gradient(0.4, 0.6,
											get_new_color(0, 255, 0),
											get_new_color(0, 255, 255)
										),
						&gradient_lst4);
	add_gradient_color(	get_new_gradient(0.6, 0.8,
											get_new_color(0, 255, 255),
											get_new_color(0, 0, 255)
										),
						&gradient_lst4);
	add_gradient_color(	get_new_gradient(0.8, 1,
											get_new_color(0, 0, 255),
											get_new_color(255, 0, 255)
										),
						&gradient_lst4);
	draw_line_aa(	&image,
					get_new_pos(10 + 80, 10), get_new_pos(10 + 80, 70),
					gradient_lst4);

	//
	win = mlx_new_window(mlx, 100, 100, (char *)"salut");
	mlx_put_image_to_window(mlx, win, image.ptr, 0, 0);

	//
	mlx_loop(mlx);

	(void)argc;
	(void)argv;
	return (0);
}
