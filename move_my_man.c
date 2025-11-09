#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>  
#include "get_next_line.h"



void find_my_man(t_game *game)
{
    int y;
    int x;

    y = 0;
    x = 0;
    while (game -> map[x])
    {
        while (game -> map[x][y])
        {
            if (game -> map[x][y] == 'P')
            {
                game -> player_x = x;
                game -> player_y = y;
                return;
            }
            y++;
        }
        x++;
        
    }
    
}

void draw_player(t_game *game)
{
    mlx_put_image_to_window(game -> mlx, game -> win,
game -> player, game -> player_x *64, game -> player_y * 64);
}
void update_game(t_game *game)
{
    mlx_clear_window(game -> mlx ,game -> win);
    img_in_map(game);
    draw_player(game);
}
void move_up(t_game *game)
{
    if (game -> map[game -> player_y - 1][game -> player_x] != '1')
    {
        game -> player_y--;
        game -> moves++;
        update_game(game);
    }
}
void move_down(t_game *game)
{
    if (game -> map[game -> player_y + 1][game -> player_x] != '1')
    {
        game -> player_y++;
        game -> moves++;
        update_game(game);
    }
}
void move_left(t_game game)
{
     if (game -> map[game -> player_y - 1][game -> player_x -1] != '1')
     {
        game -> player_y--;
        game -> moves++;
        update_game(game);
     }
}
void move_right(t_game *game)
{
    if (game -> map[game -> player_y + 1][game -> player_x + 1] != '1')
    {
        game -> player_y++;
        game -> moves++;
        update_game(game);
    }
}
