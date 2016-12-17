/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabeta.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:22:12 by tgauvrit          #+#    #+#             */
/*   Updated: 2016/12/17 19:24:55 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gomoku.h"

int		max(int a, int b)
{
	return (a >= b ? a : b);
}

int		min(int a, int b)
{
	return (a <= b ? a : b);
}

t_pos	alphabeta(t_board board, t_heuristic *prev_h, int depth, t_player player)
{
	int 	value, new_h;
	t_pos	moves[191];
	t_pos	*move;

	moves_get(board, &moves, prev_h, player, maximizing);
	move = moves;
	if (depth == 0 || alpha == INT_MAX || beta == INT_MIN)
		return *prev_h;
	if (maximizing)
	{
		value = INT_MIN;
		while (move->x != -1)
		{
			new_h = move_do(&board, prev_h, move, player, maximizing);
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
		while (move->x != -1)
		{
			new_h = move_do(&board, move, prev_h, player, maximizing);
			value = min(value, alphabeta(board, &new_h, depth - 1, alpha, beta, (player == 'w' ? 'b' : 'w'), 1));
			beta = min(beta, value);
			if (beta <= alpha)
				break ; // alpha cut-off
		}
		return value;
	}
}
