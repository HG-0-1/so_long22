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

void move_player(t_game *game, int dx,int dy)
{
    int new_x;
    int new_y;

    new_x =game -> player_x + dx;
    new_y =game -> player_y + dy;
    if(game -> map[new_x][new_y] == '1')
    {
     if(game -> map[new_x][new_y] == 'C')
     {
         game -> map[new_x][new_y] = '0';
         game -> coins_collected++;
     }
        if(game -> map[new_x][new_y] == 'E')
        {
            if(game -> coins_collected == game -> total_coins)
            {
                printf(you win)
                exit(0);
            }
                else 
                return;
        }
            game ->player_x= new_x;
            game ->player_y= new_y;
            game -> move++;
            update_game(game);
            printf(game ->move);
            
    }
    
}
void move_up(t_game *game)
{
move_player(game,0,-1);
}
void move_down(t_game *game)
{
move_player(game,0,1);
}
void move_left(t_game game)
{
    move_player(game,-1,0);
}
void move_right(t_game *game)
{
move_player(game,1,0);
}
