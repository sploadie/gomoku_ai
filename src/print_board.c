/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:08:22 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/15 10:53:58 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

void	print_board(t_board *board)
{
	int 	i, j, c;
	char	buf[BOARD_FILE_SIZE];

	c = 0;
	for (j = 0; j < 15; ++j)
	{
		for (i = 0; i < 15; ++i)
			buf[c++] = board->map[i][j];
		buf[c++] = '\n';
	}
	buf[c++] = '0' + board->white;
	buf[c++] = '0' + board->black;
	buf[c++] = '\n';
	buf[c++] = '0' + board->white5;
	buf[c++] = '0' + board->black5;
	buf[c] = '\n';
	write(1, buf, BOARD_FILE_SIZE);
}