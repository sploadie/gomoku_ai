/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:31:13 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/31 12:44:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int		move_compress(t_move move)
{
	return (move.x << 16 & move.y);
}

t_move	move_decompress(int move)
{
	t_move	new;

	new.x = move >> 16;
	new.y = move & 0xFF;
	return (new);
}

t_move	move_create(t_space x, t_space y)
{
	t_move	new;

	new.x = x;
	new.y = y;
	return new;
}

int		moves_get(t_board board, t_move *moves)
{
	int		x, base_x;
	int		y, base_y;
	t_move	*start;

	start = moves;
	for (base_x = 0; base_x < 15; ++base_x)
		for (base_y = 0; base_y < 15; ++base_y)
			if (board.map[base_x][base_y] == WHITE || board.map[base_x][base_y] == BLACK)
				for (x = base_x - 1; x <= base_x + 1; ++x)
					if (x >= 0 && x < 15)
						for (y = base_y - 1; y <= base_y + 1; ++y)
							if (y >= 0 && y < 15)
								if (board.map[x][y] == EMPTY)
								{
									moves->x = x;
									moves->y = y;
									moves++;
									board.map[x][y] = TEMPT;
								}
	return (moves - start);
}

int		moves_get_boards(t_board *board_model, t_player player, t_board *move_boards)
{
	int		x, base_x;
	int		y, base_y;
	t_board	board;
	t_board	*start;

	start = move_boards;
	board = *board_model;
	for (base_x = 0; base_x < 15; ++base_x)
		for (base_y = 0; base_y < 15; ++base_y)
			if (board.map[base_x][base_y] == WHITE || board.map[base_x][base_y] == BLACK)
				for (x = base_x - 1; x <= base_x + 1; ++x)
					if (x >= 0 && x < 15)
						for (y = base_y - 1; y <= base_y + 1; ++y)
							if (y >= 0 && y < 15)
								if (board.map[x][y] == EMPTY)
								{
									*move_boards = *board_model;
									if (heuristic_partial_move(move_boards, player, x, y) != NULL)
										move_boards++;
									board.map[x][y] = TEMPT;
								}
	return (move_boards - start);
}
