/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:49 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/20 19:47:37 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void skip_space(char *raw_map, int *i)
{
	while(raw_map[*i] == ' ' || raw_map[*i] == '\n' || raw_map[*i] == '\t')
		*i = *i + 1;
}

int check_valide_format(char *raw_map, int *i)
{
	(void)raw_map;
	(void)i;
	return (0); // flag
}
int check_char(char *raw_map, int *i)
{
	if (raw_map[*i] == '\0')
		return (0);
	if (raw_map[*i] == 'N' || raw_map[*i] == 'S' || raw_map[*i] == 'W' || raw_map[*i] == 'E')
		check_valide_format(raw_map, i);
	if(raw_map[*i] == 'F' || raw_map[*i] == 'C')
		return (0); // flag
	return (0); // flag
}
void ft_pars_raw_map(char **raw_map)
{
	int i;
	int k;
	i = 0;
	k = 0;
	while(raw_map[k])
	{
		while(raw_map[k][i] != 0)
		{
			skip_space(raw_map[k], &i);
			check_char(raw_map[k], &i);
		}
		i = 0;
		k++;
	}
}
