/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/07/06 15:14:26 by loculy           ###   ########.fr       */
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
	//box = get_hit_texture_box(main, val);
	//if (x >= 0 && x <= 2)
	//{
	//	printf("x: %d	box.x:%f	box.hit_type: %d	box.orientation: %d	box.pixel_col: %d\n", x, box.x, box.hit_type, box.orientation, box.pixel_col);
	//}
	while (x < x_max)
	{
		i = -1;
		while (++i < height)
		{
			if (box.hit_type == 2)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(90, 60, 17, 255));
			else if (box.orientation == 1)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(0, 0, 200, 255));
			else if (box.orientation == 2)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(200, 0, 0, 255));
			else if (box.orientation == 3)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(0, 200, 0, 255));
			else if (box.orientation == 4)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(0, 200, 200, 255));
		}
		x++;
	}
}
