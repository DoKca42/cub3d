#include "cub3d.h"

#include <string.h>

#define BPP sizeof(int32_t)

t_coor map_add_hitbox(int x, int y)
{
	t_coor	coor;

	coor.x = x;
	coor.y = y;
	return (coor);
}

t_map	init_map(void)
{
	t_map	map;

	map.hitbox_size = 20;
	map.hitbox = ftm_malloc((map.hitbox_size) * sizeof(t_coor));
	
	int i = 0;
	int a = 0;
	while (i < 6)
	{
		map.hitbox[a++] = map_add_hitbox(i, 0);
		map.hitbox[a++] = map_add_hitbox(i, 4);
		if (i < 4 && i != 0)
		{
			map.hitbox[a++] = map_add_hitbox(0, i);
			map.hitbox[a++] = map_add_hitbox(5, i);
		}
		i++;
	}
	map.hitbox[a++] = map_add_hitbox(4, 1);
	map.hitbox[a++] = map_add_hitbox(2, 3);
	return (map);
}

void display_mini_map(t_main *main)
{
	int i = 0;
	int x = 0;
	int y = 0;
	main->map.bck_size = 30;
	main->map.bck = ftm_malloc((main->map.bck_size) * sizeof(mlx_image_t));

	while (i < main->map.bck_size)
	{
		main->map.bck[i] =  mlx_new_image(main->mlx, 50, 50);
		if (!main->map.bck[i] || (mlx_image_to_window(main->mlx, main->map.bck[i], x * 50 + x * 2, y * 50 + y * 2) < 0))
			exit(0);
		memset(main->map.bck[i]->pixels, 255, main->map.bck[i]->width * main->map.bck[i]->height * BPP);
		if (x == 5)
		{
			x = 0;
			y++;
		}
		else
			x++;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_map	map;
	
	int i = 0;
	map = init_map();
	main.map = map;
	i = 0;
	while (i < map.hitbox_size)
	{
		printf("x : %d | y : %d\n", map.hitbox[i].x, map.hitbox[i].y);
		i++;
	}
	ft_mlx_init_build(&main);
	display_mini_map(&main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	(void)argc;
	(void)argv;
	ftm_free_all();
	return (0);
}
