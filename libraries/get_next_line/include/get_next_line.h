/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpourcel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:04:20 by kpourcel          #+#    #+#             */
/*   Updated: 2024/05/06 21:07:31 by kpourcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char *get_next_line(int fd);
char *add_to_buffer(int fd, char *buf);
char *extract_line(char *buf);
char *clear_buffer(char *buf);
void *allocate_memory(size_t num_items, size_t size);
char *join_strings(char *str1, char *str2);
char *find_char(const char *str, int char_to_find);
size_t string_length(const char *str);
#endif
