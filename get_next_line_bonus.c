/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:36 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/21 15:28:32 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_lstset_end(t_lst *lst)
{
	size_t	i;

	i = lst->end;
	while (i < lst->len)
	{
		if (lst->[i] == '\n')
		{
			lst->end = i;
			return (0);
		}
		++i;
	}
	return (-1);
}

char	*make_str_from_lst(t_lst *lst)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = lst->end - lst->bgn;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = lst->str[lst->bgn + i];
		++i;
	}
	str[len] = '\0';
	lst->end = lst->end + 1;
	lst->bgn = lst->end;
	return (str);
}

char	*read_str_from_fd(t_lst *lst, int fd)
{
	ssize_t	rt_val;
	char	*buf;

	lst = ft_lstfind_lst(lst, fd);
	if (lst == NULL)
		if (ft_lstnewadd_front(&lst, fd) != 0)
			return (NULL);
	rt_val = 0;
	while (rt_val != -1)
	{
		rt_val = read(fd, buf, BUFFER_SIZE);
		if (ft_lstappend_str(lst, buf, rt_val) != 0)
			break;
		if (ft_lstset_end(lst) == 0)
			break;	
	}
	return (make_str_from_lst(lst));
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	return (read_str_from_fd(lst, fd));
}
