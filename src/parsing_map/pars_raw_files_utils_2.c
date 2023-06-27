/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_files_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seya <seya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:59:24 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/27 23:09:08 by seya             ###   ########.fr       */
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

char	*ft_strdup_(char *s1)
{
	char	*m;
	int		i;
	int		sizes1;

	i = 0;
	sizes1 = ft_strlen_(s1);
	m = ftm_malloc((sizes1 + 1) * sizeof(char));
	if (!m)
		return (0);
	while (i < sizes1)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}