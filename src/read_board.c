/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:26:44 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/15 12:29:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

t_board		*read_board(int fd)
{
	int		i, j;
	int		ret, len;
	char 	buf[BOARD_FILE_SIZE];
	t_board	board;

	len = 0;
	while (len < BOARD_FILE_SIZE)
	{
		ret = read(fd, buf + len, BOARD_FILE_SIZE - len);
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
			board.map[i][j] = buf[(j * 16) + i];
		}
	}
	board.white = buf[BOARD_FILE_SIZE - 3] - '0';
	board.black = buf[BOARD_FILE_SIZE - 2] - '0';
	board.white5 = line5(&board, WHITE);
	board.black5 = line5(&board, BLACK);
	return memdup(&board, sizeof(t_board));
}
