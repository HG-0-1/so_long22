/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:59:04 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/06 14:12:25 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>  
#include "get_next_line.h"



int map_height()
{
int fd;
char *line;
int map_len;

map_len = 0;
fd =open("map.ber",O_RDONLY);
if (fd < 0)
    return 0;
while((line = get_next_line(fd)) != NULL)
{
    map_len++;
    free(line);
}
close(fd);
return map_len;
}

int len_of_map(char *line)
{
int len;

len = ft_strlen(line);
if(len > 0 && line[len - 1] == '\n')
    len--;
return len;
}

int rec_map(char **map,int height)
{
int width;
int i;
int len;

i = 0;
width = -1;
    while(i < height)
    {
    len = len_of_map(map[i]);
    if (width == -1)
        width = len;
    else if (len != width)
        return 0;
    i++;
    }
    return 1;

}

char **read_map(void)
{

int i;
char **map;
char *line;
int fd;

i=0;
map = malloc(sizeof(char *) * (map_height() + 1));
if(!map)
return (NULL);
fd = open("map.ber",O_RDONLY);
if (fd < 0)
{
    free(map);
    return NULL;
}
while((line = get_next_line(fd)) != NULL)
map[i++]=line;

map[i] = NULL;
close(fd);
return map;
}
