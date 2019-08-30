/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaura-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:24:29 by tsaura-n          #+#    #+#             */
/*   Updated: 2019/08/17 20:55:08 by tsaura-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char		*ft_joinnfree(char *content, char *buf)
{
	char *tmp;

	if (!content)
	{
		content = ft_strdup(buf);
		if (!content)
			return (NULL);
		return (content);
	}
	tmp = content;
	content = ft_strjoin(content, buf);
	if (!content)
		return (NULL);
	free(tmp);
	return (content);
}

t_list		*ft_lstchr(t_list *head, int fd)
{
	t_list	*node;

	node = head;
	while (node)
	{
		if (node->content_size == (size_t)fd)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_list		*find_node(t_list **head, const int fd)
{
	t_list	*node;

	if (!(*head))
	{
		node = ft_lstnew(NULL, 0);
		if (!node)
			return (NULL);
		*head = node;
		node->content_size = fd;
	}
	else
	{
		node = ft_lstchr(*head, fd);
		if (!node)
		{
			node = ft_lstnew(NULL, 0);
			if (!node)
				return (NULL);
			node->content_size = fd;
			ft_lstaddend(head, node);
		}
	}
	return (node);
}

int			line_extract(t_list *node, char **line, int a, size_t i)
{
	char	*tmoney;

	if (ft_strchr(((char *)node->content), '\n'))
	{
		while (((char *)node->content)[i] != '\n')
			++i;
		*line = ft_strndup((char *)node->content, i);
		tmoney = (char *)node->content + ++i;
		node->content = ft_strdup(tmoney);
		if (!(node->content) || !(*line))
			return (-1);
		free(tmoney - i);
		return (1);
	}
	if (a == 1 && ((char *)node->content)[0] != '\0')
	{
		*line = ft_strdup((char *)node->content);
		if (!(*line))
			return (-1);
		free(node->content);
		node->content = ft_strnew(0);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	ssize_t			i;
	t_list			*node;
	static t_list	*head;

	ft_bzero(buf, BUFF_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	node = find_node(&head, fd);
	if (!node)
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		if (i < 0)
			return (-1);
		node->content = ft_joinnfree((char *)node->content, buf);
		if (!(node->content))
			return (-1);
		ft_bzero(buf, BUFF_SIZE + 1);
		if ((i = line_extract(node, line, 0, 0)) != 0)
			return (i);
	}
	i = line_extract(node, line, 1, 0);
	return (i);
}
/*
**int			main()
**{
**	int		fd2;
**	char	*line;
**	int		buf;
**	int		z;
**	line = NULL;
**	fd = open("text.txt", O_RDONLY);
**	fd2 = open("text2.txt", O_RDONLY);
**	buf = fd;
**	while ((z = get_next_line(buf, &line)) > 0)
**	{
**		if (buf == fd)
**			buf = fd2;
**		else
**		printf("%d\t%s\n", z, line);
**		free(line);
**	}
**	system("leaks test_gnl");
**	return (0);
**}
*/
