/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 16:38:48 by crenault          #+#    #+#             */
/*   Updated: 2015/02/23 23:53:17 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../classic_mlx_helpers.h"
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

// add numbers of char
echo -ne "\x7f" > classic.bt
// size x
echo -ne "\x05\x00\x00\x00" >> classic.bt
// size y
echo -ne "\x05\x00\x00\x00" >> classic.bt
// char_nbr
echo -ne "\x41" >> classic.bt // A
// each char (x5 x5)
echo -ne "\x00\x01\x01\x01\x00" >> classic.bt
echo -ne "\x01\x00\x00\x00\x01" >> classic.bt
echo -ne "\x01\x01\x01\x01\x01" >> classic.bt
echo -ne "\x01\x00\x00\x00\x01" >> classic.bt
echo -ne "\x01\x00\x00\x00\x01" >> classic.bt



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

	/*
	** malloc big arrays
	*/
	classtext.list = (char***)ft_memalloc(classtext.list_len * sizeof(char**));
	uchar i = 0;
	while (i < classtext.list_len)
	{

		// malloc char_size.x
		classtext.list[i] = (char**)ft_memalloc(classtext.char_size.x
												* sizeof(char*));
		uint j = 0;
		while (j < classtext.char_size.x)
		{
			// malloc char_size.y
			classtext.list[i][j] = (char*)ft_memalloc(classtext.char_size.x
														* sizeof(char));
			j++;
		}
		i++;
	}

	/*
	** complete big arrays
	*/
	i = 0;
	while (i < classtext.list_len)
	{
		// get actual char_nbr
		uchar char_nb;
		uint read_len = read(fd, &char_nb, sizeof(uchar));
		if (read_len == 0)
			break ;
		printf("%d\n", char_nb);

		uint j = 0;
		if (char_nb < classtext.list_len)
		{
			while (j < classtext.char_size.x)
			{
				uint k = 0;
				while (k < classtext.char_size.y)
				{
					read(fd, &classtext.list[char_nb][j][k], sizeof(char));
					printf("%d ", classtext.list[char_nb][j][k]);
					k++;
				}
				printf("\n");
				j++;
			}
		}
		i++;
		printf("\n");
	}
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
