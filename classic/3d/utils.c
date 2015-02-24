/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 12:01:51 by rbenjami          #+#    #+#             */
/*   Updated: 2015/02/24 13:53:59 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../classic_mlx_helpers.h"

float		to_radians(float angle)
{
	return (angle * M_PI / 180);
}

float		rt(float val)
{
	return (val * val);
}
