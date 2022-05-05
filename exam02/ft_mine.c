/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namohamm <namohamm@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:36:43 by namohamm          #+#    #+#             */
/*   Updated: 2022/03/24 18:25:39 by namohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count(char const *s, char c)
{
	int	count;
	int i;

	i = 0;
	count = 0;
	while (s[i++])
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	return (count);
}

char *ft_words(char const *s, char c)
{
	char *word;
	int i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(i + 1);
	if (!word)
		return (NULL);
	/*
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	*/
	for (int i = 0; s[i] && s[i] != c; i++)
		word[i] = s[i];
	word[i] = '\0';
	return (word);
}

char **ft_split(char const *s, char c)
{
	char **tab;
	int i = 0;
	int words = ft_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))	
			return (NULL);
	while(*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i++] = ft_words(s, c);
			while(*s && *s != c)
				s++;
		}
	}
	tab[i] = NULL;
	return (tab);
}

int main()
{
	char *s = "  hello  nass lol  kill";
	char c = ' ';
	
	int i = 0;
	char **tab;
	tab = ft_split(s, c);
	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	return (0);
}
