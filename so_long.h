/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:58:54 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/08 18:53:30 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*player;
	void	*player1;
	int		*player_x;
	int		*player_y;
	void	*collectible;
	void	*exit;
	void	*floor;
	char	**map;
	int		width;
	int		height;
	int		img_w;
	int		img_h;
	int		moves;
}			t_game;

# define key_esc 65307
# define key_w 119
# define key_a 97
# define key_s 115
# define key_d 100

# include <stdio.h>
//move
void		move_up(t_game *game);
void		move_left(t_game *game);
void		move_down(t_game *game);
void		move_right(t_game *game);
//wall
int			check_wall_tandb(char **map, int width, int height);
int			check_wall_side(char **map, int width, int height);
int			check_element(char **map, int height, int width);
//map
int			map_height(void);
int			len_of_map(char *line);
int			rec_map(char **map, int height);
char		**read_map(void);

int			key_hook(int keycode, t_game *game);

void		load_img(t_game *game);
void		img_in_map(t_game *game);

#endif