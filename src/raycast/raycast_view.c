/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/07/06 18:03:45 by loculy           ###   ########.fr       */
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
			//if ((int)(box.pixel_col / 5) < 0 || (int)(box.pixel_col / 5) >= 100 || (int)(i / 5) < 0 || (int)(i / 5) >= 100)
			//{
			//	printf("orientation: %d\n", box.orientation);
			//}
			if (box.hit_type == 2)
				mlx_put_pixel(main->map->view, x, i + y, main->png[4].pixels[(int)(box.pixel_col / 5)][(int)(i / 5)]);
			else if (box.orientation == 1)
				mlx_put_pixel(main->map->view, x, i + y, main->png[0].pixels[(int)(box.pixel_col / 5)][(int)(i / 5)]);
			else if (box.orientation == 2)
				mlx_put_pixel(main->map->view, x, i + y, main->png[1].pixels[(int)(box.pixel_col / 5)][(int)(i / 5)]);
			else if (box.orientation == 3)
				mlx_put_pixel(main->map->view, x, i + y, main->png[2].pixels[(int)(box.pixel_col / 5)][(int)(i / 5)]);
			else if (box.orientation == 4)
				mlx_put_pixel(main->map->view, x, i + y, main->png[3].pixels[(int)(box.pixel_col / 5)][(int)(i / 5)]);
		}
		x++;
	}
}
