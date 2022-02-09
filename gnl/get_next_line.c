/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:52:50 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/09 13:08:13 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin2(char *save, char *ret, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (save && save[i] != '\0')
	{
		ret[i] = save[i];
		i++;
	}
	if (!line)
	{
		ret[i] = '\0';
		return (ret);
	}
	while (line[++j] != '\0')
	{
		ret[i] = line[j];
		i++;
	}
	ret[i] = '\0';
	free(save);
	return (ret);
}

char	*ft_strjoin(char *save, char *line)
{
	char	*ret;

	ret = malloc(sizeof(char) * (ft_strlen(save) + ft_strlen(line) + 1));
	if (!ret)
	{
		free(save);
		return (NULL);
	}
	ret = ft_strjoin2(save, ret, line);
	return (ret);
}

char	*ft_save_line(int i, char save[BUFFER_SIZE + 1], int fd)
{
	int		index;
	char	*s1;
	char	*line;

	line = NULL;
	while (i > 0)
	{
		index = ft_get_index(save);
		s1 = ft_strdup(save, index);
		line = ft_strjoin(line, s1);
		free(s1);
		if (save[index] == '\n')
		{
			ft_update_save(save, index);
			line = ft_strjoin(line, "\n");
			return (line);
		}
		else
		{
			i = read(fd, save, BUFFER_SIZE);
			save[i] = '\0';
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line; //str que je vais return
	static char	save[BUFFER_SIZE + 1]; //la str sur laquelle je travaille
	int			i;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	i = 1;
	if (save[0] == '\0')
	{
		i = read(fd, save, BUFFER_SIZE);
		save[i] = '\0';
	}
	line = NULL;
	line = ft_save_line(i, save, fd);
	return (line);
}

int	main()
{
	int fd = open("text.txt", O_RDONLY);
	char *result;

	while ((result = get_next_line(fd)) != NULL)
	{
		printf("%s", result);
		free(result);
	}
	free(result);
//	system("leaks a.out");
	return (0);
}