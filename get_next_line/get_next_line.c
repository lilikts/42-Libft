/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:02:29 by lkloters          #+#    #+#             */
/*   Updated: 2025/01/31 14:40:51 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *remainder)
{
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;
	char		*temp;

	read_bytes = 1;
	if (!remainder)
	{
		remainder = (char *)malloc(1 * sizeof(char));
		if (!remainder)
			return (NULL);
		remainder[0] = '\0';
	}
	while (!(ft_strchr(remainder, '\n')) && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(remainder), NULL);
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		if (!temp)
			return (NULL);
		remainder = temp;
	}
	return (remainder);
}

char	*string_line(char *remainder)
{
	int		length;
	char	*new_string;
	int		i;

	i = 0;
	length = 0;
	if (ft_strchr(remainder, '\n'))
		length = ft_strchr(remainder, '\n') - remainder + 1;
	else
		length = ft_strlen(remainder);
	new_string = (char *)malloc((length + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < length)
	{
		new_string[i] = remainder[i];
		i++;
	}
	new_string[length] = '\0';
	return (new_string);
}

char	*update(char *remainder, int length)
{
	char	*updated_remainder;
	int		total_len;
	int		temp;

	temp = length;
	total_len = ft_strlen(remainder);
	if (temp >= total_len)
	{
		updated_remainder = (char *)malloc(1 * sizeof(char));
		if (!updated_remainder)
			return (NULL);
		updated_remainder[0] = '\0';
		return (updated_remainder);
	}
	updated_remainder = (char *)malloc(((total_len - temp + 1)) * sizeof(char));
	if (!updated_remainder)
		return (NULL);
	length = 0;
	while (remainder[temp] != '\0')
		updated_remainder[length++] = remainder[temp++];
	updated_remainder[length] = '\0';
	return (updated_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX + 1];
	char		*new_string;
	char		*updated_remainder[OPEN_MAX + 1];

	remainder[fd] = read_line(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	if (remainder[fd][0] == '\0')
	{
		free (remainder[fd]);
		return (remainder[fd] = NULL, NULL);
	}
	new_string = string_line(remainder[fd]);
	if (!new_string)
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (NULL);
	}
	updated_remainder[fd] = update(remainder[fd], ft_strlen(new_string));
	free(remainder[fd]);
	remainder[fd] = updated_remainder[fd];
	if (!updated_remainder[fd])
		return (free(new_string), NULL);
	return (new_string);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *get_line;

// 	while (1)
// 	{
// 			get_line = get_next_line(fd);
// 			if (!get_line)
// 				break;
// 			printf("%s", get_line);
// 	}
// 	return 0;
// }
