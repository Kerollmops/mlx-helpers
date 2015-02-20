/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:33:03 by crenault          #+#    #+#             */
/*   Updated: 2015/02/20 23:12:16 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned char	uchar;

/*
** image structure
*/
typedef struct			s_image
{
	void				*mlx; // is it good ?

	void				*ptr;
	char				*data;
	int					bpp;	// bits per pixel
	int					sl;		// size line
	int					endian;

	int					width;
	int					height;

}						t_image;

/*
** color structure
*/
typedef struct			s_color
{
	uchar				r;
	uchar				g;
	uchar				b;

}						t_color;

/*
** gradient structure
*/
typedef struct			s_gradient
{
	double				min;
	double				max;
	t_color				start;
	t_color				stop;

}						t_gradient;

/*
** position structure
*/
typedef struct			s_pos
{
	int					x;
	int					y;

}						t_pos;

#endif
