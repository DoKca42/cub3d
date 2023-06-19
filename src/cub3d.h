/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:05:00 by loculy            #+#    #+#             */
/*   Updated: 2023/06/19 17:24:52 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../memory_manager/memory_manager.h"
# include "../lib/ft_rprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# define WIDTH 2560
# define HEIGHT 1440
# define TOOLBAR 130

# define PL_SPEED 4

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_map
{
	t_coor	*hitbox;
	int		hitbox_size;

	char	**map;

	mlx_image_t	**bck;
	int			bck_size;
}	t_map;


typedef struct s_main
{
	void	*mlx;
	t_map	map;
}	t_main;

int	ft_mlx_init_build(t_main *main);

#endif