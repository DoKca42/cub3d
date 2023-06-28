/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:22:02 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 20:55:19 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	deg_to_rad(int angle)
{
	double	rad;

	rad = ((double)angle * PI) / 180;
	return (rad);
}

float	distance_from_main(t_main *main, t_dblcoor val)
{
	float	distance;

	distance = sqrtf(powf((val.x - main->ray->x), 2)
			+ powf((val.y - main->ray->y), 2));
	return (distance);
}

int	mini_distance(t_main *main, t_dblcoor hori, t_dblcoor verti)
{
	float	h;
	float	v;

	h = distance_from_main(main, hori);
	v = distance_from_main(main, verti);
	if (h < v)
		return (0);
	else
		return (1);
}
