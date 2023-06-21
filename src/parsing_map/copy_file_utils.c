/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmorue <mmorue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:03:30 by mmorue            #+#    #+#             */
/*   Updated: 2023/06/21 15:06:56 by mmorue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void ft_free_tab(char **tab)
{
	int i;

	i = -1;
	while(tab[++i])
		ftm_free(tab[i]);
	ftm_free(tab);
}
char	*ft_strdup_modif(char *s1)
{
	char	*m;
	int		i;
	int		sizes1;

	i = 0;
	sizes1 = ft_strlen(s1);
	m = (char *)malloc((sizes1) * sizeof(char));
	if (!m)
		return (0);
	while (i < sizes1 - 1)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

void clean_map(t_main *main, char **raw_map)
{
	int k;

	k = 0;
	while(raw_map[k])
	{
		if(raw_map[k][ft_strlen(raw_map[k]) - 1] == '\n')
			main->clean_file[k] = ft_strdup_modif(raw_map[k]);
		else
			main->clean_file[k] = ft_strdup(raw_map[k]);
		k++;
	}
}