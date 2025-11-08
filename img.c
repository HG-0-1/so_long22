#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>  
#include "get_next_line.h"

void load_img(t_game *game)
{
game->wall =   mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm",&game->img_w, &game->img_h);
game->player = mlx_xpm_file_to_image(game->mlx, "./images/player.xpm",&game->img_w, &game->img_h);
game->collectible = mlx_xpm_file_to_image(game->mlx, "./images/collectible.xpm",&game->img_w, &game->img_h);
game->exit = mlx_xpm_file_to_image(game->mlx, "./images/exit.xpm",&game->img_w, &game->img_h);
game->floor = mlx_xpm_file_to_image(game->mlx, "./images/floor.xpm",&game->img_w, &game->img_h);
game->player1 = mlx_xpm_file_to_image(game->mlx, "./images/player1.xpm",&game->img_w, &game->img_h);


} 
void img_in_map(t_game *game)
{
    int i;
    int j;
    char c;

    i = 0;
    j = 0;
    while (i < game->height)
    {
        j = 0;
        while (j < game->width)
        {
           c = game->map[i][j];
            if(c == '1')
            mlx_put_image_to_window(game->mlx,game->win,game->wall,j * 64, i* 64);
            else if(c == '0')
            mlx_put_image_to_window(game->mlx,game->win,game->floor,j * 64, i* 64);
            else if(c == 'E')
            mlx_put_image_to_window(game->mlx,game->win,game->exit,j * 64, i* 64);
            else if(c == 'C')
            mlx_put_image_to_window(game->mlx,game->win,game->collectible,j * 64, i* 64);
            else if(c == 'P')
            mlx_put_image_to_window(game->mlx,game->win,game->player,j * 64, i* 64);
        j++;
        }
        i++;
    }
    
}


