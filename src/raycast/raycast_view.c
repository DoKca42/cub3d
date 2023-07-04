/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/06/30 00:33:56 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_main *main, int x, int height, t_dblcoor val)
{
	int		y;
	int		i;
	int		x_max;
	t_hit	box;

	y = HEIGHT / 2 - height / 2;
	x_max = x + 1;
	box = get_hit_texture_box(main, val);
	while (x < x_max)
	{
		i = 0;
		while (i < height)
		{
			//mlx_put_pixel(main->map->view, x, i + y, ft_pixel(150, 150, 150, 255));
			if (box.orientation == 1)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(0, 0, 200, 255));
			else if (box.orientation == 2)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(200, 0, 0, 255));
			else if (box.orientation == 3)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(0, 200, 0, 255));
			else if (box.orientation == 4)
				mlx_put_pixel(main->map->view, x, i + y, ft_pixel(0, 200, 200, 255));
			i++;
		}
		x++;
	}
}
