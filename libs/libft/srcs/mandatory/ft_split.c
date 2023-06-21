/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:17:49 by jdagoy            #+#    #+#             */
/*   Updated: 2022/10/21 12:47:17 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		words++;
	}
	return (words);
}

static char	**ft_free(char **splittab)
{
	int	i;

	i = 0;
	while (splittab[i])
	{	
		free(splittab[i]);
		i++;
	}
	free(splittab);
	return (NULL);
}

static char	**ft_splitwords(char **split, const char *s, char c, size_t words)
{
	size_t	wordcheck;
	size_t	splitcheck;
	size_t	i;

	wordcheck = 0;
	splitcheck = 0;
	i = 0;
	while (wordcheck < words)
	{
		if (s[i] == c || i >= ft_strlen(s))
		{
			if (splitcheck != 0)
			{
				split[wordcheck] = ft_substr(s, i - splitcheck, splitcheck);
				if (!split[wordcheck])
					return (ft_free(split));
				wordcheck++;
			}
			splitcheck = 0;
		}
		else
			splitcheck++;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**splitwords;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	splitwords = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splitwords)
		return (NULL);
	ft_splitwords(splitwords, s, c, words);
	splitwords[words] = NULL;
	return (splitwords);
}
