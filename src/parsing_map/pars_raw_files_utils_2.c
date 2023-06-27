/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_files_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:59:24 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/27 17:05:42 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void convert_color(char **color, t_rgb *rgb)
{
	rgb->r = ft_atoi(color[0]);
	rgb->g = ft_atoi(color[1]);
	rgb->b = ft_atoi(color[2]);

	if (rgb->r > 255 || rgb->g > 255 || rgb->b > 255)
		ft_errormap("wrong RGB format");
}