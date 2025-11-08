/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:58:58 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/08 17:28:22 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>  
#include "get_next_line.h"



void free_map(char **map)
{
    int i;
    
    i = 0;
    if (!map)
    return;
    while(map[i])
        free(map[i++]);
    free(map);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == key_esc)
    exit(0);
    else if (keycode == key_w)
    move_up(game);
    else if (keycode == key_a)
    move_left(game);
    else if(keycode == key_d)
    move_right(game);
    else if(keycode == key_s)
    move_down(game);
    return(0);
}



int main(void)
{
char **map;
int height;
int width;
t_game game;

map =read_map();
if(!map)
{
    //ft_printf("%s","Error: cannot read map\n");
    return 1;
}
height = map_height();
if (height <= 0)
{
    free_map(map);
    //ft_printf("%s","Error: invalid map height\n");
    return 1;
}
width = len_of_map(map[0]);
if (!rec_map(map,height) || !check_wall_tandb(map,width,height)
|| !check_wall_side(map,width,height) || !check_element(map,height,width))
{
    free_map(map);
    //ft_printf("%s","Error: invalid map\n");
    return 1;
}
game.map = map;
game.width = width;
game.height = height;

game.mlx = mlx_init();
game.win = mlx_new_window(game.mlx, width * 64, height * 64 , "so_long");

load_img(&game);
if (!game.wall || !game.floor || !game.exit || !game.player || !game.collectible)
{
    printf("Error: failed to load one or more images\n");
    return (1);
}

img_in_map(&game);

mlx_key_hook(game.win,key_hook, &game);
mlx_loop(game.mlx);

mlx_destroy_window(game.mlx,game.win);
free_map(map);
return 0;
}





/*



Expose Hook – إعادة رسم النافذة
int expose_hook(void *param)
{
    draw_map(param);
    return(0);
}

🔄 Loop Hook – تحديث مستمر (اختياري)

mlx_loop_hook(mlx_ptr, loop_hook, &game_data);


تشغيل الحلقة الرئيسية
mlx_loop(mlx_ptr);

تنشئ صورة جديدة في الذاكرة (بدون عرضها بعد).
mlx_new_image(void *mlx_ptr, int width, int height)


ترجع عنوان الذاكرة الذي يخزن بيانات الصورة (البكسلات نفسها).
mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)


تعرض الصورة داخل النافذة في الموقع (x, y)
mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y)


تحوّل قيمة اللون من RGB عادي (0xRRGGBB) إلى القيمة المناسبة حسب تنسيق الصورة (bits_per_pixel و endian).
mlx_get_color_value(void *mlx_ptr, int color)



تحمّل صورة XPM من مصفوفة في الكود (مثلًا إذا خزّنت صورة XPM داخل ملف .c).
5. mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height)



تحمّل صورة XPM من ملف خارجي (غالبًا تستعملها في مشروع so_long لتحميل الخلفية أو اللاعب أو الجدران).
mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height)


تحذف الصورة من الذاكرة لتحرير الموارد.
mlx_destroy_image(void *mlx_ptr, void *img_ptr)


تنشئ نافذة جديدة على الشاشة.
mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)


تمسح محتوى النافذة (أي تجعلها سوداء بالكامل).
mlx_clear_window(void *mlx_ptr, void *win_ptr)

تغلق النافذة وتزيلها من الشاشة وتحرر مواردها من الذاكرة.
mlx_destroy_window(void *mlx_ptr, void *win_ptr)


استخدام mlx_loop() لتبقى النافذة تعمل وتتعامل مع الأحداث (مثل الضغط على لوحة المفاتيح أو إغلاق النافذة).


ترسم بكسل واحد فقط (نقطة واحدة) داخل النافذة عند إحداثيات معينة (x, y).
int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);


تطبع نصًّا (string) داخل النافذة عند موقع معين، بلون محدد.
int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

*/









