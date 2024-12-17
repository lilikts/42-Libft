/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 08:43:51 by lkloters          #+#    #+#             */
/*   Updated: 2024/12/10 09:57:49 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	numb_of_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*copy_word(char *s, int length)
{
	char	*word;

	word = ft_calloc(length + 1, sizeof(char));
	if (word == 0)
		return (0);
	ft_strlcpy(word, s, length + 1);
	return (word);
}

static void	free_mem(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;
	int		i;
	int		length;

	count = numb_of_words(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		length = 0;
		while (*s != '\0' && *s == c)
			s++;
		while (s[length] != '\0' && s[length] != c)
			length++;
		result[i] = copy_word((char *)s, length);
		if (result[i] == 0)
			return (free_mem(result, i - 1), NULL);
		s = s + length;
		i++;
	}
	result[i] = NULL;
	return (result);
}
