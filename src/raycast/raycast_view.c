/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:10:41 by loculy            #+#    #+#             */
/*   Updated: 2023/06/29 19:56:36 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rectangle(t_main *main, int x, int height, int width)
{
	int	middle_map;
	int	middle_height;
	int	y;
	int	i;
	int	x_max;

	middle_map = HEIGHT / 2;
	middle_height = height / 2;
	y = middle_map - middle_height;
	x_max = x + width;
	while (x < x_max)
	{
		i = 0;
		while (i < height)
		{
			mlx_put_pixel(main->map->view, x, i + y, ft_pixel(150, 150, 150, 255));
			i++;
		}
		x++;
	}
}
