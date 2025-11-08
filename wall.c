/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helfayez <helfayez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 08:58:50 by helfayez          #+#    #+#             */
/*   Updated: 2025/11/06 14:11:52 by helfayez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

int	check_wall_tandb(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
int	check_wall_side(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}


int	check_element(char **map, int height, int width)
{
	int	player;
	int	exit;
	int	collectible;
	int	i;
	int	j;

	i = 0;
	player = 0;
	exit = 0;
	collectible = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'P')
				player++;
			else if (map[i][j] == 'E')
				exit++;
			else if (map[i][j] == 'C')
				collectible++;
			else if (map[i][j] != '0' && map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	if (player != 1 || exit < 1 || collectible < 1)
		return (0);
	return (1);
}
