/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 23:23:33 by crenault          #+#    #+#             */
/*   Updated: 2015/02/20 23:24:32 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_helpers.h"

t_pos			get_new_pos(int x, int y)
{
	t_pos		position;

	position.x = x;
	position.y = y;
	return (position);
}
