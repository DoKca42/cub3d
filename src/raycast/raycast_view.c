/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/07/10 13:52:28 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_main *main, int x, int height, t_hit box)
{
	int		y;
	int		i;
	int		x_max;

	y = HEIGHT / 2 - height / 2;
	x = x * 2;
	x_max = x + 2;
	while (x < x_max)
	{
		i = -1;
		while (++i < height)
		{
			if (y + i >= 0 && y + i < HEIGHT)
			{
				if (box.hit_type == 2)
					mlx_put_pixel(main->map->view, x, i + y, main->png[4].pixels[pixels_convert_ratio_width(main, main->png[4], box.pixel_col)][pixels_convert_ratio_height(main, main->png[4], i, height)]);
				else if (box.orientation == 1)
					mlx_put_pixel(main->map->view, x, i + y, main->png[0].pixels[pixels_convert_ratio_width(main, main->png[0], box.pixel_col)][pixels_convert_ratio_height(main, main->png[0], i, height)]);
				else if (box.orientation == 2)
					mlx_put_pixel(main->map->view, x, i + y, main->png[1].pixels[pixels_convert_ratio_width(main, main->png[1], box.pixel_col)][pixels_convert_ratio_height(main, main->png[1], i, height)]);
				else if (box.orientation == 3)
					mlx_put_pixel(main->map->view, x, i + y, main->png[2].pixels[pixels_convert_ratio_width(main, main->png[2], box.pixel_col)][pixels_convert_ratio_height(main, main->png[2], i, height)]);
				else if (box.orientation == 4)
					mlx_put_pixel(main->map->view, x, i + y, main->png[3].pixels[pixels_convert_ratio_width(main, main->png[3], box.pixel_col)][pixels_convert_ratio_height(main, main->png[3], i, height)]);
			}
		}
		x++;
	}
}

int	pixels_convert_ratio_width(t_main *main, t_pixtex png, int i)
{
	int	out;

	//(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	out = (i - 0) * (png.width - 1 - 0) / (MAP_RES - 0) + 0;
	(void)main;
	return (out);
}


int	pixels_convert_ratio_height(t_main *main, t_pixtex png, int i, int height)
{
	int	out;

	//(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
	out = (i - 0) * (png.height - 1 - 0) / (height - 0) + 0;
	(void)main;
	return (out);
}

/* ==== DEBUG === */
void	pixels_display(t_main *main, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		printf("i:%d pixels:%d\n", i, pixels_convert_ratio_height(main, main->png[0], i, height));
		i++;
	}
}
