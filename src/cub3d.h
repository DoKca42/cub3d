/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:05:00 by loculy            #+#    #+#             */
/*   Updated: 2023/06/28 15:27:27 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "stdio.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
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

# define PI 3.14159265

typedef struct s_inpt
{
	int		right;
	int		left;
	int		up;
	int		down;
	int		speed;
}	t_inpt;

typedef struct s_dblcoor
{
	double	x;
	double	y;
}	t_dblcoor;

typedef struct s_coor
{
	int	x;
	int	y;
}	t_coor;

typedef struct s_door
{
	t_coor	coor;
	int		open;
}	t_door;

typedef struct s_player
{
	int	x;
	int	y;
	int	direc;
}	t_player;

typedef struct s_cooldown
{
	int	door;
	int	fire;
	int	pause;
}	t_cooldown;

typedef struct s_raycast
{
	double	x;
	double	y;
	double	xn;
	double	yn;
}	t_raycast;

typedef struct s_map
{
	char		**map;

	t_coor		*wall;
	int			wall_size;

	t_door		*door;
	int			door_size;

	mlx_image_t	**img_bck;
	int			bck_size;

	t_player	start;
	t_player	current;

	mlx_image_t	*img_player;

	mlx_image_t	*ray_lines;
}	t_map;

typedef struct s_texture
{
	char	**no;
	char	**so;
	char	**we;
	char	**ea;
	char	**f;
	char	**c;
}	t_texture;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_main
{
	void		*mlx;
	char		**clean_file;
	char		**map_tab;
	t_texture	*text;
	t_rgb		*sol;
	t_rgb		*ciel;
	t_map		*map;
	t_cooldown	*cooldown;
	t_raycast	*ray;
	int			pause;
}	t_main;

/* ======= MLX ====== */
int			ft_mlx_init_build(t_main *main);
void		fill_color_image(mlx_image_t *image, uint32_t color);
int32_t		ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

/* ======= MAP ====== */
t_coor		map_add_hitbox(int x, int y);
t_map		init_map_wall(t_map map);
t_map		init_map(t_map map);
int			get_map_size(char **map);
int			get_map_hitbox_size(char **map, char c);
t_coor		get_map_maxsize(char **map);
t_main		*get_main(void *input);
void		init_main(t_main *main);

/* ======= UTILS ====== */
int			ft_strlen_(char *str);
int			get_max(int a, int b);
int			get_min(int a, int b);

/* ======= PLAYER ====== */
t_map		init_map_player(t_map map);
t_player	set_player(int x, int y, int orientation);
int			orientation_to_angle(char orientation);

/* ======= MINIMAP ====== */
void		display_mini_map(t_main *main);
void		display_mini_map_player(t_main *main);

/* ======= ACTION ====== */
void		ft_player_rotation(t_main *main);
void		ft_player_move(t_main *main, t_inpt input);
void		player_get_rotation(t_main *main);
void		player_get_move(t_main *main);
void		player_get_action(t_main *main);
void		ft_player_init_input(t_inpt *input, t_main *main);
void		set_mv(t_main *main, int x, int y);
void		update_player(t_main *main, int x, int y);
void		mlx_mouse(t_main *main);

/* ======= COLLISION ====== */
int			is_wall_collision(int x, int y, t_player current, t_coor wall);
void		player_move_wall(t_main *main, int type, int x, int y);
void		player_move_door(t_main *main, int type, int x, int y);

/* ======= POSITION ====== */
t_coor		get_case_player(t_main *main);
t_coor		get_case_coor(t_coor coor);
t_coor		get_center_player(t_main *main);
t_dblcoor	get_dblcenter_player(t_main *main);
t_coor		get_case_dbcoor(t_dblcoor coor);

/* ======= RAYCASTING ====== */
void		ray_set_player_pose(t_main *main);
t_dblcoor	ray_get_yn_xn(t_main *main);
t_dblcoor	ray_horizontal(t_dblcoor pose, int direc);
void		raycast(t_main *main);

/* ======= RAYCASTING COLLISION ====== */
int			raycast_get_collision(t_dblcoor n_coor, t_main *main);

/* ======= RAYCASTING UTILS ====== */
double		deg_to_rad(int angle);

/* ======= DDA ====== */
void		init_ray_view(t_main *main);
void		draw_line(int xa, int ya, int xb, int yb);
void		dda_incr(float x, float y, int step, t_coor dcoor);
int			get_abs(int value);

/* ======= TIME ====== */
int			ft_delta_time(t_main *main);
int			get_time(t_main *main);
t_cooldown	init_cooldown(void);

/* ======= COPY_FILE ====== */
int			get_file(t_main *main, char *str);
int			check_ber(char *str);
int			ft_errormap(char *str);
int			read_map(int fd);
int			checkline(char *buffer);
/* ======= COPY_FILE_UTILS ====== */
char		*ft_strdup_modif(char *s1);
void		clean_map(t_main *main, char **raw_map);
void		ft_free_tab(char **tab);
int			ft_strcmp(char *s1, char *s2);

/* ======= PARS_RAW_FILE ====== */
void		ft_pars_raw_map(char **raw_map, t_main *main);
int			check_char(char *raw_map, int *i, t_main *main);
int			check_valide_format(char *raw_map, int *i, t_texture *text);
char		**check_routine(char *raw_map, char **texture, char *to_compare);
char		**check_color_format(char *raw_map, int *i, char **rgb);

/* ======= PARS_RAW_FILE_UTILS ====== */
int			strlen_doubletab(char **tab);
void		skip_space(char *raw_map, int *i);
void		check_color_char(char *str);
int			check_valide_texture(t_texture *text);
int			check_char_for_map(char	*tab);

/* ======= PARS_RAW_FILE_UTILS_2 ====== */
void		convert_color(char **color, t_rgb *rgb);
char		*ft_strdup_(char *s1);
void		ft_copy_map(char **raw_map, t_main *main, int k);
/* ======= SPLIT_MODIF ====== */
char		**ft_split_modif(char const *str, char *c);
int			check_char_tab_split(char c, char *str);

/* ======= PARS_CLEAN_MAP ====== */
void		check_arround(char **map, int i, int k);
void		ft_pars_clean_map(char	**map);
int			char_player(char c);
int			char_to_check_around(char c);
int			check_char_clean_map(char c, int cases);

#endif