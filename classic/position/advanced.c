/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 00:30:04 by crenault          #+#    #+#             */
/*   Updated: 2015/02/22 16:17:08 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"

t_fpos				lerp(t_fpos a, t_fpos b, const double t)
{
	t_fpos		dest;

	dest.x = a.x + (b.x - a.x) * t;
	dest.y = a.y + (b.y - a.y) * t;
	return (dest);
}

void			add_position(t_fpos pos, t_list **lst)
{
	ft_lstpush(lst, ft_lstnew(&pos, sizeof(t_fpos)));
}

t_list			*get_pos_node(t_list *lst, size_t n)
{
	size_t			i;

	if (lst)
	{
		i = 0;
		while (lst != NULL)
		{
			if (i == n)
				return (lst);
			lst = lst->next;
			i++;
		}
	}
	if (MLX_HELPERS_DEBUG == 1)
		ft_putendl_fd("get_pos_node: can't find node", 2);
	return (NULL);
}

void			del_pos_list(t_list **lst)
{
	while ((*lst) != NULL)
	{
		ft_lstpop(lst);
	}
}
