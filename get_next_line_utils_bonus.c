/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:22:52 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/21 16:06:13 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_lstnewadd_front(t_lst **lst, int fd)
{
	t_lst	*new;

	if (!lst)
		return (-1);
	new = (t_lst *)malloc(sizeof(*new));
	if (!new)
		return (-2);
	new->fd = fd;
	new->str = (char *)malloc(sizeof(char) * 1);
	if (new->str == NULL)
		return (-3);
	new->bgn = 0;
	new->end = 0;
	new->len = 0;
	new->cap = 1;
	new->next = NULL;
	if (*lst)
		new->next = *lst;
	*lst = new;
	return (0);
}

t_lst	*ft_lstfind_lst(t_lst *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int	ft_lstcap_up(t_lst *lst, size_t new_cap)
{
	size_t	i;
	char	*new_str;

	if (!lst || lst->cap > new_cap)
		return (-1);
	new_str = (char *)malloc(sizeof(char) * new_cap);
	if (!new_str)
		return (-2);
	i = 0;
	while (i < lst->len)
	{
		new_str[i] = lst->str[i];
		++i;
	}
	free(lst->str);
	lst->str = new_str;
	lst->cap = new_cap;
	return (0);
}

int	ft_lstclear(t_lst *lst)
{
	t_lst	*tmp;

	if (!lst)
		return (-1);
	tmp = lst;
	while (lst)
	{
		free(lst->str);
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}

int	ft_lstappend_str(t_lst *lst, char *buf, size_t len)
{
	size_t	i;
	int		rt;

	rt = -1;
	if ((size_t)(-1) - len < lst->len)
		return (rt);
	if (lst->len + len > lst->cap)
	{
		if (lst->len + len > lst->cap * 2)
			rt = ft_lstcap_up(lst, lst->len + len);
		else
			rt = ft_lstcap_up(lst, lst->cap * 2);
	}
	if (rt != 0)
		return (rt);
	i = 0;
	while (i < len)
	{
		lst->str[lst->len + i] = buf[i];
		++i;
	}
	lst->len = lst->len + len;
	ft_lstset_end(lst);
	return (0);
}
