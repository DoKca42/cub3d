/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:22:11 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 13:13:34 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void display_mini_map(t_main *main)
{
	t_map	map;
	int i = 0;
	int x = 0;
	int y = 0;
	
	map = main->map;
	main->map.bck_size = get_map_size(map.map);
	main->map.bck = ftm_malloc((main->map.bck_size) * sizeof(mlx_image_t));
	while (map.map[y] != 0)
	{
		x = 0;
		while (map.map[y][x] != 0)
		{
			main->map.bck[i] =  mlx_new_image(main->mlx, MN_MAP_RES, MN_MAP_RES);
			if (!main->map.bck[i] || (mlx_image_to_window(main->mlx, main->map.bck[i], x * MN_MAP_RES, y * MN_MAP_RES) < 0))
				exit(0);
			if (map.map[y][x] == '1')
				fill_color_image(main->map.bck[i], ft_pixel(255, 255, 255, 255));
			else
				fill_color_image(main->map.bck[i], ft_pixel(255, 255, 255, 25));
			i++;
			x++;
		}
		y++;
	}
}