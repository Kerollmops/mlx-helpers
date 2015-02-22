/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:33:03 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 00:43:41 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef unsigned char	uchar;
typedef unsigned int	uint;

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
**
** float: better gradients
*/
typedef struct			s_color
{
	float				r;
	float				g;
	float				b;
	float				alpha;

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

/*
** position with double composants structure
*/
typedef struct			s_fpos
{
	double				x;
	double				y;

}						t_fpos;

#endif
