/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:47:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2017/01/17 15:18:38 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_H
# define GOMOKU_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

# define BOARD_FILE_SIZE 243
# define MINIMAX_DEPTH 4
# define MAX_MOVES 192
# define EMPTY '.'
# define TEMPT '@'
# define WHITE 'w'
# define BLACK 'b'
# define ERROR 'E'

# ifdef USE_INT
typedef uint32_t		t_space;
# else
typedef unsigned char	t_space;
# endif

typedef struct			s_heuristic
{
	int		free_three;
	int		free_four;
	int		five_win;
	int		captured;
}						t_heuristic;

typedef struct			s_move
{
	// uint32_t:16			x;
	// uint32_t:16			y;
	uint32_t			x;
	uint32_t			y;
}						t_move;

typedef struct			s_ab
{
	int					alpha;			// maximizing
	int					beta;			// minimizing
}						t_ab;

typedef struct			s_player
{
	t_space				color;
	int					maximizing;
}						t_player;

typedef struct			s_board
{
	t_space				map[15][15];
	// uint32_t:16			black;
	// uint32_t:16			black5;
	// uint32_t:16			white;
	// uint32_t:16			white5;
	uint32_t			black;
	uint32_t			black5;
	uint32_t			white;
	uint32_t			white5;
	int					h;
}						t_board;

// GLOBALS
int			g_alphabeta_depth = 4;

// FUNCTION DECLARATIONS
t_board		*read_board(int fd);
void		print_board(t_board *board);

t_player	player_create(int color, int maximizing);
t_player	player_switch(t_player player);
t_player	player_maximizing(t_player player);

t_ab		ab_new(void);
int			alphabeta(t_board board, int depth, t_ab ab, t_player player);

int			move_compress(t_move move);
t_move		move_decompress(int move);
int			move_count(t_move *moves);
void		moves_get(t_board board, t_player player, t_move *moves);

int			board_isvalid(int x, int y);
int			board_capture(t_board *board, int x, int y);

void		*memdup(void *data, size_t len);

#endif
