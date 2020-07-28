/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdaemoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:08:02 by vdaemoni          #+#    #+#             */
/*   Updated: 2020/01/26 14:16:24 by vdaemoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		cpy_till_endl(char **dest, char **src)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((tmp = ft_strchr(*src, ENDL)))
		i = tmp - *src;
	if (!tmp)
	{
		*dest = ft_strdup(*src);
		ft_strclr(*src);
		return ;
	}
	*dest = ft_strsub(*src, 0, i);
	tmp = *src;
	if ((*src + i) != 0)
	{
		*src = ft_strdup(*src + i + 1);
		free(tmp);
	}
	else
		ft_strclr(*src);
}

static t_list	*appropriate(const int fd, t_list **head)
{
	t_list *tmp;

	if (!head)
		return (NULL);
	tmp = *head;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	ft_lstadd(head, tmp);
	return (tmp);
}

static int		reading(const int fd, char **str)
{
	ssize_t	res;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	while ((res = read(fd, buff, BUFF_SIZE)))
	{
		buff[res] = 0;
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buff)))
			return (-1);
		free(tmp);
		if (ft_strrchr(buff, ENDL))
			break ;
	}
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*curr;
	ssize_t			res;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 ||
			(!(curr = appropriate(fd, &head))))
		return (-1);
	res = reading(fd, (char **)&(curr->content));
	tmp = curr->content;
	if (!res && !*tmp)
		return (0);
	cpy_till_endl(line, (char **)&(curr->content));
	return (1);
}
