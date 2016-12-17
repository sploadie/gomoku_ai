/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabeta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:22:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 15:01:28 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

t_pos	alphabeta(t_board board, int *prev_h, int depth, int alpha, int beta, char player, int maximizing)
{
	int 	value, new_h;
	t_pos	moves[191];
	t_pos	*move;

	moves_get(board, player, &moves);
	move = moves;
	if (depth == 0 || alpha == INT_MAX || beta == INT_MIN)
		return *prev_h;
	if (maximizing)
	{
		value = INT_MIN;
		while (move->x != -1)
		{
			new_h = move_do(&board, move, player, maximizing);
			value = max(value, alphabeta(board, &new_h, depth - 1, alpha, beta, (player == 'w' ? 'b' : 'w'), 0));
			alpha = max(alpha, value);
			if (beta <= alpha)
				break ; // beta cut-off
			move++;
		}
		return value;
	}
	else
	{
		value = INT_MAX;
		while ()
		{
			new_h = move_do(&board, move, player, maximizing);
			value = min(value, alphabeta(board, &new_h, depth - 1, alpha, beta, (player == 'w' ? 'b' : 'w'), 1));
			beta = min(beta, value);
			if (beta <= alpha)
				break ; // alpha cut-off
		}
		return value;
	}
}
