#include "cub3d.h"

t_coor map_add_hitbox(int x, int y)
{
	t_coor	coor;

	coor.x = x;
	coor.y = y;
	return (coor);
}

int	main(int argc, char **argv)
{
	t_main	main;
	t_map	map;


	

	map.hitbox_size = 22;
	map.hitbox = ftm_malloc((map.hitbox_size) * sizeof(t_coor));
	
	int i = 0;
	int a = 0;
	while (i < 6)
	{
		map.hitbox[a++] = map_add_hitbox(0, i);
		map.hitbox[a++] = map_add_hitbox(4, i);
		if (i < 5)
		{
			map.hitbox[a++] = map_add_hitbox(i, 0);
			map.hitbox[a++] = map_add_hitbox(i, 5);
		}
	}
	map.hitbox[a++] = map_add_hitbox(4, 1);
	map.hitbox[a++] = map_add_hitbox(2, 3);


	main.map = map;
	i = 0;
	while (i < map.hitbox_size)
	{
		printf("x : %d | y : %d\n", map.hitbox[i].x, map.hitbox[i].y);
		i++;
	}
	(void)argc;
	(void)argv;
	ftm_free_all();
	return (0);
}
