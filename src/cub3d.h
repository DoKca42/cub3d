/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:05:00 by loculy            #+#    #+#             */
/*   Updated: 2023/06/20 19:38:26 by loculy           ###   ########.fr       */
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

# define MN_MAP_RES 50
# define MN_PLAYER_RES 25

# define MAP_RES 50
# define PLAYER_RES 25

# define PLY_SPEED 4
# define PLY_FOV 60

typedef struct s_inpt
{
	int		right;
	int		left;
	int		up;
	int		down;
	int		speed;
}	t_inpt;

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_player
{
	int	x;
	int	y;
	int	orientation;
}	t_player;

typedef struct s_map
{
	char		**map;

	t_coor		*hitbox;
	int			hitbox_size;

	mlx_image_t	**img_bck;
	int			bck_size;

	t_player	start;
	t_player	current;

	mlx_image_t	*img_player;
}	t_map;


typedef struct s_main
{
	void	*mlx;
	t_map	*map;
}	t_main;

/* ======= MLX ====== */
int			ft_mlx_init_build(t_main *main);
void		fill_color_image(mlx_image_t *image, uint32_t color);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

/* ======= MAP ====== */
t_coor		map_add_hitbox(int x, int y);
t_map		init_map_hitbox(t_map map);
t_map		init_map(t_map map);
int			get_map_size(char **map);
int			get_map_hitbox_size(char **map);

/* ======= PLAYER ====== */
t_map		init_map_player(t_map map);
t_player	set_player(int x, int y, int orientation);
int			orientation_to_angle(char orientation);

/* ======= MINIMAP ====== */
void 		display_mini_map(t_main *main);
void 		display_mini_map_player(t_main *main);

/* ======= ACTION ====== */
void		ft_player_move(t_main *main, t_inpt input);
void		player_getmove(t_main *main);
void		ft_player_init_input(t_inpt *input, t_main *main);
void		set_mv(t_main *main, int x, int y);
void		update_player(t_main *main, int x, int y);

/* ======= COLLISION ====== */
int			is_wall_collision(int x, int y, t_player current, t_coor wall);
int			player_move_wall(t_main *main, int type, int x, int y);

/* ======= TIME ====== */
int			ft_delta_time(t_main *main);


#endif