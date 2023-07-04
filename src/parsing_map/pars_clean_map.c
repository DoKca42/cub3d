/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_clean_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:39:24 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/29 16:07:08 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_arround(char **map, int i, int k)
{
	if (k == 0 || k == strlen_doubletab(map) - 1)
		ft_errormap("bad wall");
	if (i > ft_strlen_(map[k - 1]) || i > ft_strlen_(map[k + 1]))
		ft_errormap("bad wall");
	if (i == 0)
		ft_errormap("bad wall");
	if (check_char_clean_map(map[k - 1][i], 2) == 0)
		ft_errormap("bad wall");
	if (check_char_clean_map(map[k + 1][i], 2) == 0)
		ft_errormap("bad wall");
	if (check_char_clean_map(map[k][i - 1], 2) == 0)
		ft_errormap("bad wall");
	if (check_char_clean_map(map[k][i + 1], 2) == 0)
		ft_errormap("bad wall");
}

void	check_door(char **map, int i, int k)
{
	if ((map[k - 1][i] == '1' && map[k + 1][i] == '1') || (map[k][i - 1] == '1' && map[k][i + 1] == '1'))
		return ;
	else
		ft_errormap("No wall for door");
}
void	ft_pars_clean_map(char	**map)
{
	int	k;
	int	i;
	int	player;

	k = -1;
	player = 0;
	while (map[++k])
	{
		i = -1;
		while (map[k][++i])
		{
			if (!check_char_clean_map(map[k][i], 1))
				ft_errormap("bad char in map");
			if (char_to_check_around(map[k][i]))
				check_arround(map, i, k);
			if (map[k][i] == 'D')
				check_door(map, i, k);
			if (char_player(map[k][i]))
				player++;
		}
	}
	if (player != 1)
		ft_errormap("wrong number of player");
}

int	char_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W' )
		return (1);
	return (0);
}

int	char_to_check_around(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D')
		return (1);
	return (0);
}

int	check_char_clean_map(char c, int cases)
{
	if (cases == 1)
		if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
			|| c == 'W' || c == 'D' || c == ' ' || c == '\t')
			return (1);
	if (cases == 2)
		if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E'
			|| c == 'W' || c == 'D')
			return (1);
	return (0);
}
