/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:59:44 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 21:11:44 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

/* find_char: Recherche un caractère spécifique dans une chaîne de caractères */
char	*find_char(const char *str, int char_to_find)
{
	while (*str != (char)char_to_find)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

/* string_length: Calcule la longueur d'une chaîne de caractères */
size_t	string_length(const char *str)
{
	size_t	length;

	if (!str)
		return (0);
	length = 0;
	while (str[length])
		length++;
	return (length);
}

/* clear_memory: Initialise les n premiers octets du bloc 
mémoire pointé par ptr à zéro */
void	clear_memory(void *ptr, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/* allocate_memory: Alloue de la mémoire tout en initialisant
 le contenu à zéro */
void	*allocate_memory(size_t num_items, size_t size)
{
	void	*ptr;

	ptr = malloc(num_items * size);
	if (!ptr)
		return (NULL);
	clear_memory(ptr, num_items * size);
	return (ptr);
}

/* join_strings: Concatène deux chaînes de caractères en une nouvelle chaîne */
char	*join_strings(char *str1, char *str2)
{
	int		i;
	int		k;
	char	*result;

	if (!str1)
	{
		str1 = (char *)malloc(1 * sizeof(char));
		str1[0] = '\0';
	}
	if (!str2 || !str1)
		return (NULL);
	result = malloc(sizeof(char) * ((string_length(str1)
					+ string_length(str2)) + 1));
	if (!result)
		return (NULL);
	i = -1;
	while (str1[++i])
		result[i] = str1[i];
	k = -1;
	while (str2[++k])
		result[i + k] = str2[k];
	result[i + k] = '\0';
	free(str1);
	return (result);
}
