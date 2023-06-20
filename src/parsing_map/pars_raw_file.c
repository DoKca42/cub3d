/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_raw_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:34:49 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/20 18:03:30 by mmorue           ###   ########.fr       */
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
	
}
int check_char(char *raw_map, int *i)
{
	if (raw_map[*i] == '\0');
		return (0);
	if (raw_map[*i] == 'N' || raw_map[*i] == 'S' || raw_map[*i] == 'W' || raw_map[*i] == 'E')
		check_valide_format();
	if(raw_map[*i] == 'F' || raw_map[*i] == 'C')
	
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