/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:36 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/21 19:45:07 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_lstset_end(t_lst *lst)
{
	while (lst->end < lst->len - 1)
	{
		if (lst->str[lst->end] == '\n')
			return (0);
		++(lst->end);
	}
	return (-1);
}

char	*make_str_from_lst(t_lst *lst)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (lst->end == lst->len)
		return (NULL);
	len = lst->end - lst->bgn + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = lst->str[lst->bgn + i];
		++i;
	}
	if (lst->str[lst->end] == '\n')
		str[len - 1] = '\n';
	str[len] = '\0';
	lst->end = lst->end + 1;
	lst->bgn = lst->end;
	ft_lstset_end(lst);
	return (str);
}

char	*read_str_from_fd(t_lst **lst, t_lst *now, int fd)
{
	ssize_t	rt_val;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (1)
	{
		rt_val = read(fd, buf, BUFFER_SIZE);
		if (rt_val == 0 || rt_val == -1)
			break ;
		if (ft_lstappend_str(now, buf, rt_val) != 0)
			break ;
		if (now->str[now->end] == '\n')
			break ;
	}
	free(buf);
	if (rt_val == -1 || now->str == NULL)
		return (ft_lstdel_one(lst, fd));
	return (make_str_from_lst(now));
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	t_lst			*now;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (lst == NULL)
	{
		if (ft_lstnewadd_front(&lst, fd) != 0)
			return (NULL);
		now = lst;
	}
	else
	{
		now = ft_lstfind_lst(lst, fd);
		if (now == NULL)
		{
			if (ft_lstnewadd_front(&lst, fd) != 0)
				return (NULL);
			now = lst;
		}
	}
	return (read_str_from_fd(&lst, now, fd));
}
