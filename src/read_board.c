/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:26:44 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 13:09:33 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

t_board		*read_board(int fd)
{
	int		i, j;
	int		ret, len;
	char 	buf[243];
	t_board	board;

	len = 0;
	while (len < 243)
	{
		ret = read(fd, buf + len, 243 - len);
		if (ret < 1)
		{
			perror("Input");
			exit(1);
		}
		len += ret;
	}
	for (i = 0; i < 15; ++i)
	{
		for (j = 0; j < 15; ++j)
		{
			board.map[i][j] = buf[(i * 16) + j];
		}
	}
	board.white = buf[240] - '0';
	board.black = buf[241] - '0';
	return memdup(&board, sizeof(t_board));
}
