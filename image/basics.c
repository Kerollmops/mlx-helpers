/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:43:16 by crenault          #+#    #+#             */
/*   Updated: 2015/02/21 11:38:29 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_helpers.h"

t_image			get_new_image(void *mlx, int width, int height)
{
	t_image		img;

	img.mlx = mlx;
	img.ptr = mlx_new_image(mlx, width, height);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.sl, &img.endian);
	img.width = width;
	img.height = height;
	return (img);
}

# pragma message("todo: manage endian")
# pragma message("todo: binary moves (hexa var)")
void			put_pixel_image(t_image *image, t_pos p, t_color color)
{
	unsigned int	hex_color;
	unsigned int	hexa;
	unsigned int	i;

	if (p.x >= 0 && p.x < image->width && p.y >= 0 && p.y < image->height)
	{
		hexa = ((color.r & 0xFF) << image->bpp / 2) +
				((color.g & 0xFF) << image->bpp / 4) + (color.b & 0xFF);
		hex_color = mlx_get_color_value(image->mlx, hexa);
		i = p.y * image->sl + (image->bpp / 8) * p.x;
		image->data[i] = (hex_color & 0xFF);
		image->data[i + 1] = (hex_color & 0xFF00) >> 8;
		image->data[i + 2] = (hex_color & 0xFF0000) >> 16;
		return ;
	}
	#pragma message("if debug(define) then display error on cerr")
	ft_putendl_fd("put_pixel_image: out of image", 2);
}

# pragma message("todo: manage endian and mlx_get_color_value")
t_color			get_pixel_image(t_image *image, t_pos p)
{
	t_color			color;
	unsigned int	i;

	// if not good return not initialized color ? or black ? or ... ?
	if (p.x >= 0 && p.x < image->width && p.y >= 0 && p.y < image->height)
	{
		i = p.y * image->sl + (image->bpp / 8) * p.x;
		color.r = image->data[i + 2];
		color.g = image->data[i + 1];
		color.b = image->data[i];
	}
	#pragma message("if debug(define) then display error on cerr")
	ft_putendl_fd("get_pixel_image: out of image", 2);
	return (color);
}

void			clear_image(t_image *image)
{
	ft_bzero(image->data, (image->width + 32) * image->height * 4);
}
