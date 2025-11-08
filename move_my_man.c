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


void update_game(t_game *game)
{
    mlx_clear_window(game -> mlx ,game -> win);
    dr
}
void move_to_up(t_game *game)
{
    if (game -> map[game -> player - 1][game -> player_x] != '1')
    {
        game -> player_y--;
        game -> moves++;
        update_game(game);
    }
}
void move_to_down(t_game *game)
{
    if (game -> map[game -> player + 1][game -> player_x] != '1')
    {
        game -> player_y++;
        game -> moves++;
        update_game(game);
    }
}