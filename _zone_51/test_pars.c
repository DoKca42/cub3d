#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../lib/get_next_line/get_next_line.h"
#include "../memory_manager/memory_manager.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
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

char	*ft_strdup(char *s1)
{
	char	*m;
	int		i;
	int		sizes1;

	i = 0;
	sizes1 = ft_strlen(s1);
	m = (char *)malloc((sizes1 + 1) * sizeof(char));
	if (!m)
		return (0);
	while (i < sizes1)
	{
		m[i] = s1[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

int	checkline(char *buffer)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			size++;
		i++;
	}
	return (size);
}

int	read_map(int fd)
{
	char	buffer[2];
	int		size;

	buffer[1] = '\0';
	size = 1;
	if (read(fd, 0, 0) < 0 || fd < 0)
		return (1);
	while (read(fd, buffer, 1) > 0)
		size += checkline(buffer);
	close(fd);
	return (size);
}

int	ft_errormap(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(str);
	write(1, "Error\n", 6);
	write(1, str, k);
	write(1, "\n", 1);
	ftm_free_all();
	exit (1);
}

int	check_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c'
		|| str[i - 4] != '.')
		return (ft_errormap("map isn't .cub"));
	return (1);
}

int get_file(char* str)
{
	int i;
	int size;
	int fd;
	int k;
	char **copy_file;
	char **final_version;
	i = 0;
	k = 0;
	size = read_map(ftm_open(str, O_RDONLY));
	copy_file = malloc((size + 1) * sizeof(char *));
	final_version = malloc((size + 1) * sizeof(char *));
	copy_file[size] = 0;
	final_version[size] = 0;
	fd = ftm_open(str, O_RDONLY);
	while (i < size)
		copy_file[i++] = get_next_line(fd);
	ftm_close(fd);
	i = 0;
	while(copy_file[k])
	{
		if(copy_file[k][ft_strlen(copy_file[k]) - 1] == '\n')
			final_version[k] = ft_strdup_modif(copy_file[k]);
		else
			final_version[k] = ft_strdup(copy_file[k]);
		k++;
	}
	k = 0;
	while(copy_file[k])
		printf("%s\n", final_version[k++]);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_errormap("wrong number of args"));
	if (check_ber(argv[1]) == 0)
		return (0);
	get_file(argv[1]);
}