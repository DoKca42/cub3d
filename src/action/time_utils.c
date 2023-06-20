/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:10:33 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 18:10:51 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_delta_time(t_main *main)
{
	int		b;
	mlx_t	*mlx;

	mlx = main->mlx;
	b = (int)(mlx->delta_time * 100);
	if (b > 1)
		b = b / 2;
	return (b);
}
