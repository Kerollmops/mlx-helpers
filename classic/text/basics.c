/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:38:48 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 18:44:39 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx_helpers.h"
#include <unistd.h>
#include <fcntl.h>

/*
127 5 5
0 00000 00000 00000 00000 00000
1 ...
...

nbr_char size_x size_y
char_nbr ..... ..... ..... .....
char_nbr ...
...

unsigned_char unsigned_int unsigned_int
unsigned_char char char char char...
unsigned_char ...
...

echo -ne "\x7f" > classic.bt
echo -ne "\x05\x00\x00\x00" >> classic.bt

// max int
echo -ne "\xff\xff\xff\xff" >> classic.bt

*/

t_classtext			get_classtext(const char *file_path)
{
	t_classtext		classtext;
	int				fd;

	fd = open(file_path, O_RDONLY);
	read(fd, &classtext.list_len, sizeof(uchar));
	read(fd, &classtext.char_size.x, sizeof(uint));
	read(fd, &classtext.char_size.y, sizeof(uint));

	printf(">> %d (%u, %u)\n", classtext.list_len, classtext.char_size.x,
					classtext.char_size.y);

	close(fd);
	return (classtext);
}

t_size				get_classtext_size(t_classtext *classtext, const char *text)
{
	t_size		size;

	(void)classtext;
	(void)text;
	//
	size.x = 5;
	size.y = 5;
	return (size);
}
