/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 01:54:11 by vdaemoni          #+#    #+#             */
/*   Updated: 2019/09/16 18:09:24 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ncpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] != 0 && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_strclen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static int	ft_hm(char const *s, char c)
{
	int i;
	int res;
	int flag;

	flag = 1;
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c && s[i] != 0)
		{
			flag = 1;
			while (s[i] == c && s[i] != 0)
				i++;
		}
		if (s[i] != c && s[i] != 0)
		{
			if (flag == 1)
				res++;
			flag = 0;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	return (res);
}

static void	ft_free(char **ptr, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**copy;

	j = -1;
	i = 0;
	if (!s || (!(copy = (char **)malloc(sizeof(char *) * (ft_hm(s, c) + 1)))))
		return (NULL);
	while (s[i] == c)
		i++;
	while (++j < ft_hm(s, c))
	{
		if ((!(copy[j] = malloc(ft_strclen(&s[i], c) + 1))))
		{
			ft_free(copy, j);
			return (NULL);
		}
		copy[j] = ft_ncpy(copy[j], &s[i], ft_strclen(&s[i], c));
		i = ft_strclen(&s[i], c) + i;
		while (s[i] == c)
			i++;
	}
	copy[j] = NULL;
	return (copy);
}
