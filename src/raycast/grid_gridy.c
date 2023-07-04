/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_gridy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:13:59 by loculy            #+#    #+#             */
/*   Updated: 2023/07/04 14:56:47 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_grid(t_main *main)
{
	t_map	*map;

	map = main->map;
	map->grid = ftm_malloc((1) * sizeof(mlx_image_t));
	map->grid = mlx_new_image(main->mlx, get_map_maxsize(map->map).x
			* MN_MAP_RES, get_map_maxsize(map->map).y * MN_MAP_RES);
	if (!map->grid || (mlx_image_to_window(main->mlx, map->grid, 0, 0)
			< 0))
		exit(0);
	fill_color_image(map->grid, ft_pixel(255, 255, 255, 0));
}

void	dda_incr_grid(float x, float y, int step, t_coor dcoor)
{
	float	xdda;
	float	ydda;
	int		i;
	t_main	*main;
	t_map	*map;

	main = get_main(0);
	map = main->map;
	xdda = dcoor.x / (float)step;
	ydda = dcoor.y / (float)step;
	i = 0;
	while (i < step)
	{
		if (x < map->width * MN_MAP_RES && y < map->height * MN_MAP_RES)
			mlx_put_pixel(map->grid, (uint32_t)x, (uint32_t)y, ft_pixel(133, 133, 133, 255));
		x += xdda;
		y += ydda;
		i++;
	}
}

void	draw_line_grid(int xa, int ya, int xb, int yb)
{
	int		dx;
	int		dy;
	int		step;
	t_coor	dcoor;

	dx = xb - xa;
	dy = yb - ya;
	step = get_max(get_abs(dx), get_abs(dy));
	dcoor.x = dx;
	dcoor.y = dy;
	dda_incr_grid((float)xa, (float)ya, step, dcoor);
}

void	grid_mlx(t_main *main)
{
	int		i;
	t_coor	size;

	i = 0;
	size = get_map_maxsize(main->map_tab);
	while (i < size.y)
	{
		draw_line_grid(0, i * MN_MAP_RES, size.x * MN_MAP_RES, i * MN_MAP_RES);
		i++;
	}
	i = 0;
	while (i < size.x)
	{
		draw_line_grid(i * MN_MAP_RES, 0, i * MN_MAP_RES, size.y * MN_MAP_RES);
		i++;
	}
}
