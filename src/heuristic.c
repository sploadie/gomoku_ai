/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 10:53:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/17 17:18:10 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

// int	info[9];
// int[ 0:space_start, 1:space_end, 2:second_space, 3:free_three, 4:free_four, 5:five_win, 6:aligned, 7:total, 8:captured]
// x2 for maximizing(0) and minimizing(1) players
// #define SPACE_START  0
// #define SPACE_END    1
// #define SECOND_SPACE 2
// #define FREE_THREE   3
// #define FREE_FOUR    4
// #define FIVE_WIN     5
// #define ALIGNED      6
// #define TOTAL        7
// #define CAPTURED     8

// void		heuristic_calc(t_board *board)
// {
// 	// FIXME
// 	board->h = 0;
// }

// void		heuristic_calc_pos_line(t_board *board, int maximizing_color, t_move pos, int mod_x, int mod_y, int info[][])
// {
// 	int m, n;
// 	int minimizing_color;

// 	minimizing_color = (maximizing_color == WHITE ? BLACK : WHITE);
// 	for (m = -4; m < 1; ++m)
// 	{
// 		if (board_isvalid(pos.x + mod_x*(m-1), pos.y + mod_y*(m-1)) && board->map[pos.x + mod_x*(m-1)][pos.y + mod_y*(m-1)])
// 		{
// 			info[0][SPACE_START] = 1;
// 			info[1][SPACE_START] = 1;
// 		}
// 		if (board_isvalid(pos.x + mod_x*(m+5), pos.y + mod_y*(m+5)) && board->map[pos.x + mod_x*(m+5)][pos.y + mod_y*(m+5)])
// 		{
// 			info[0][SPACE_END] = 1;
// 			info[1][SPACE_END] = 1;
// 		}
// 		for (n = m; n < m + 5; ++n)
// 		{
// 			if (board_isvalid(pos.x + mod_x*n, pos.y + mod_y*n) == 0)
// 				continue ;
			
// 		}
// 	}
// }

// void		heuristic_calc_pos(t_board *board, t_player player, t_move pos, int info[][])
// {
// 	player = player_maximizing(player);

// 	if (player.color == WHITE) {
// 		info[0][CAPTURED] = board->white;
// 		info[1][CAPTURED] = board->black;
// 	} else {
// 		info[0][CAPTURED] = board->black;
// 		info[1][CAPTURED] = board->white;
// 	}
// }

// // Sets valid to 1 if valid move
// // Else sets valid to 0
// int			heuristic_calc_move(t_board board, t_player player, t_move move, int *valid)
// {
// 	// // FIXME
// 	// (void)player;
// 	// (void)move;
// 	// valid = 1;
// 	// board->h = 0;
// 	int	capture;
// 	int	info[2][2][8];

// 	board->map[move.x][move.y] = player.color;
// 	capture = board_capture(&board, move.x, move.y);
// }

t_board		*heuristic_partial_move(t_board *board, t_player one, int move_x, int move_y)
{
	t_heuristic hrc[2];
	t_player	two;
	int			count;

	// Create player two info
	two = player_switch(one);
	// Clear heuristic table
	bzero(hrc, sizeof(hrc));
	// Set chip
	board->map[move_x][move_y] = one.color;
	// Handle capture and line5
	count = board_capture(board, move_x, move_y);
	// If no capture, check for double free three
	// ==========================================================================================
	// FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME FIXME 
	// ==========================================================================================
	// Grab heuristic values
	if (one.color == WHITE)
	{
		// Player
		hrc[one.maximizing].five_win = board->white5;
		hrc[one.maximizing].captured = board->white;
		// Opponent
		hrc[two.maximizing].five_win = board->black5;
		hrc[two.maximizing].captured = board->black;
	}
	else
	{
		// Player
		hrc[one.maximizing].five_win = board->black5;
		hrc[one.maximizing].captured = board->black;
		// Opponent
		hrc[two.maximizing].five_win = board->white5;
		hrc[two.maximizing].captured = board->white;
	}
	// Calculate partial heuristic
	board->h = heuristic_calculate(hrc);
	return board;
}

t_board		heuristic_full_board(t_board *board)
{
	;
}
