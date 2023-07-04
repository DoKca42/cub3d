/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:22:11 by loculy            #+#    #+#             */
/*   Updated: 2023/07/04 16:09:42 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void display_mini_map(t_main *main)
{
	t_map	*map;
	int i = 0;
	int x = 0;
	int y = 0;
	
	map = main->map;
	map->bck_size = get_map_size(map->map);
	map->img_bck = ftm_malloc((map->bck_size) * sizeof(mlx_image_t));
	while (map->map[y] != 0)
	{
		x = 0;
		while (map->map[y][x] != 0 && map->map[y][x] != '\n')
		{
			map->img_bck[i] = mlx_new_image(main->mlx, MN_MAP_RES, MN_MAP_RES);
			if (!map->img_bck[i] || (mlx_image_to_window(main->mlx, map->img_bck[i], x * MN_MAP_RES, y * MN_MAP_RES) < 0))
				exit(0);
			if (map->map[y][x] == '1')
				fill_color_image(map->img_bck[i], ft_pixel(255, 255, 255, 255));
			else if (map->map[y][x] == 'D')
				fill_color_image(map->img_bck[i], ft_pixel(255, 25, 255, 255));
			else
				fill_color_image(map->img_bck[i], ft_pixel(255, 255, 255, 25));
			i++;
			x++;
		}
		y++;
	}
}

void display_mini_map_player(t_main *main)
{
	t_map	*map;

	map = main->map;
	map->img_player = ftm_malloc((1) * sizeof(mlx_image_t));
	map->img_player = mlx_new_image(main->mlx, MN_PLAYER_RES, MN_PLAYER_RES);
	if (!map->img_player || (mlx_image_to_window(main->mlx, map->img_player, map->start.x / 20, map->start.y / 20) < 0))
		exit(0);
	fill_color_image(map->img_player, ft_pixel(25, 255, 255, 255));
}
