/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 21:33:03 by crenault          #+#    #+#             */
/*   Updated: 2015/02/24 10:26:29 by rbenjami         ###   ########.fr       */
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

typedef struct			s_vec2f
{
	float				x;
	float				y;
}						t_vec2f;

typedef struct			s_vec3f
{
	float				x;
	float				y;
	float				z;
}						t_vec3f;

typedef struct			s_quat
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_quat;

typedef struct			s_mat4
{
	float				m[4][4];
}						t_mat4;

typedef struct			s_vert
{
	t_vec3f				pos;
	t_vec3f				color;
}						t_vert;

typedef struct			s_tran
{
	t_vec3f				pos;
	t_vec3f				scale;
	t_quat				rot;
}						t_tran;

#endif
