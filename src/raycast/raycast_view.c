/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/07/04 17:21:02 by loculy           ###   ########.fr       */
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
	x = x * 2;
	x_max = x + 2;
	box = get_hit_texture_box(main, val);
	while (x < x_max)
	{
		i = -1;
		while (++i < height)
		{
			if (box.orientation == 1)
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
