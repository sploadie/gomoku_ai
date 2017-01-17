/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:50:05 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/17 17:16:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int		board_isvalid(int x, int y)
{
	if (x < 0 || x >= 15 || y < 0 || y >= 15)
		return 0;
	return 1;
}

// Player chip should ALREADY be placed!
int		board_capture(t_board *board, int x, int y)
{
	int 	i, j;
	int 	capture;
	t_space	p, o;

	capture = 0;
	p = board->map[x][y]
	o = (p == WHITE ? BLACK : WHITE);
	for (i = -1; i <= 1; ++i)
	{
		for (j = -1; j <= 1; ++j)
		{
			if (i == 0 && j == 0)
				continue;
			if (board_isvalid(x + i  , y + j  ) && board->map[x + i  ][y + j  ] == o
			 && board_isvalid(x + i*2, y + j*2) && board->map[x + i*2][y + j*2] == o
			 && board_isvalid(x + i*3, y + j*3) && board->map[x + i*3][y + j*3] == p)
			{
				if (p == WHITE)
				{
					board->white += 2;
					board->black5 -= line5_point_all(board, x + i  , y + j  );
					board->black5 -= line5_point_all(board, x + i*2, y + j*2);
				}
				else
				{
					board->black += 2;
					board->white5 -= line5_point_all(board, x + i  , y + j  );
					board->white5 -= line5_point_all(board, x + i*2, y + j*2);
				}
				board->map[x + i  ][y + j  ] = EMPTY;
				board->map[x + i*2][y + j*2] = EMPTY;
				capture += 2;
			}
		}
	}
	if (p == WHITE)
		board->white5 += line5_point_all(board, x, y);
	else
		board->black5 += line5_point_all(board, x, y);
	return capture;
}

// Player chip should ALREADY be placed!
uint32_t	line5_point_all(t_board *board, int x, int y)
{
	int		i, j, k, m, player_color, count;

	player_color = board->map[x][y];
	count = 0;
	for (i = 0; i <= 1; ++i)
		for (j = -1; j <= 1; ++j)
			if (i == 1 || j == -1)
				for (k = -4, k <= 0; ++k)
				{
					for (m = k; m <= k+4; ++m)
					{
						if (board_isvalid(x+i*m, y+j*m) && board->map[x+i*m][y+j*m] == player_color)
							continue;
						break;
					}
					if (m == 5)
						++count;
				}
	return count;
}

uint32_t	line5_point(t_board *board, int color, int x, int y)
{
	int		i, j, m, count;

	count = 0;
	for (i = 0; i <= 1; ++i)
	{
		for (j = -1; j <= 1; ++j)
		{
			if (i == 0 && (j == 0 || j == 1))
				continue;
			for (m = 1; m <= 4; ++m)
			{
				if (!board_isvalid(x+i*m, y+j*m) || board->map[x+i*m][y+j*m] != color)
					break;
			}
			if (m == 5)
				++count;
		}
	}
	return count;
}

// Examines full board!
uint32_t	line5(t_board *board, int color)
{
	int		x, y, count;

	count = 0;
	for (x = 0; x < 15; ++x)
	{
		for (y = 0; y < 15; ++y)
		{
			if (board->map[x][y] == color)
				count += line5_point(board, color, x, y);
		}
	}
	return count;
}
