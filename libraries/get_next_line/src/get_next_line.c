/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:57:24 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 21:04:39 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/* readNextLine: Lire la ligne suivante d'un fichier et gérer un buffer statique */
char *get_next_line(int fd) 
{
    static char *buf[4096];
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) 
    {
        free(buf[fd]);
        buf[fd] = NULL;
        return NULL;
    }
    buf[fd] = add_to_buffer(fd, buf[fd]);
    if (!buf[fd])
        return NULL;
    line = extract_line(buf[fd]);
    buf[fd] = clear_buffer(buf[fd]);
    return line;
}

/* add_to_buffer: Ajoute les données lues au buffer jusqu'à rencontrer un '\n' */
char	*add_to_buffer(int fd, char *buf)
{
	char	*temp_buf;
	int		bytes_read;

	bytes_read = 1;
	temp_buf = allocate_memory(BUFFER_SIZE + 1, sizeof(char));
	while (bytes_read != 0)
	{
		bytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp_buf);
			return (NULL);
		}
		temp_buf[bytes_read] = '\0';
		buf = join_strings(buf, temp_buf);
		if (find_char(temp_buf, '\n'))
			break ;
	}
	free(temp_buf);
	return (buf);
}

/* extract_line: Extrait une ligne complète du buffer jusqu'à '\n' inclus */
char	*extract_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = allocate_memory(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

/* create_new_buffer: Crée un nouveau buffer à partir de la position après '\n' */
char	*create_new_buffer(char *buf, int i)
{
	int		j;
	char	*new_buf;

	new_buf = allocate_memory((string_length(buf) - i + 1), sizeof(char));
	if (!new_buf)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
	{
		new_buf[j] = buf[i];
		i++;
		j++;
	}
	return (new_buf);
}

/* clear_buffer: Nettoie le buffer en créant un nouveau à partir du dernier '\n' trouvé */
char	*clear_buffer(char *buf)
{
	int		i;
	char	*new_buf;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	new_buf = create_new_buffer(buf, i);
	free(buf);
	if (new_buf[0] == '\0')
	{
		free(new_buf);
		return (NULL);
	}
	return (new_buf);
}
