/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:28:37 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/21 15:33:07 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fctnl.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*line;
	fd = open("./file", O_RDONLY);

	if (fd = -1)
		printf("file open failed\n");
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}
