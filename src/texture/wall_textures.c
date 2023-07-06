/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:22:49 by loculy            #+#    #+#             */
/*   Updated: 2023/07/05 17:51:18 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_texture_secu(int i, char *str, t_texture *tex)
{
	tex->all[i] = mlx_load_png(str);
	if (!tex->all[i])
		ft_errormap("Invalid texture file");
}

void	wall_textures_load(t_main *main)
{
	t_texture	*tex;
	int			size;
	int			i;

	tex = main->text;
	i = 0;
	if (main->door == 1)
		size = 5;
	else
		size = 4;
	tex->all = ftm_malloc((size) * sizeof(mlx_texture_t));
	load_texture_secu(i++, tex->no[1], tex);
	load_texture_secu(i++, tex->so[1], tex);
	load_texture_secu(i++, tex->we[1], tex);
	load_texture_secu(i++, tex->ea[1], tex);
	if (main->door == 1)
		load_texture_secu(i++, tex->dr[1], tex);
}
