/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:01:51 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/23 14:03:41 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

float		to_radians(float angle)
{
	return (angle * M_PI / 180);
}

float		rt(float val)
{
	return (val * val);
}
