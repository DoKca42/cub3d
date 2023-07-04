/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:45:56 by loculy            #+#    #+#             */
/*   Updated: 2023/06/29 18:10:32 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	height_distance(int distance)
{
	int			height;

	height = HEIGHT - distance * 3;
	if (height < 0)
		height = 0;
	if (height > HEIGHT)
		height = HEIGHT;
	return (height);
}
