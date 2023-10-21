/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyusulee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:28:37 by kyusulee          #+#    #+#             */
/*   Updated: 2023/10/21 16:13:27 by kyusulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
	int		fd;
	char	*line;
	fd = open("./file", O_RDONLY);

	if (fd == -1)
		printf("file open failed\n");
	printf("BUFFER SIZE : %d\n", BUFFER_SIZE);
	printf("before1\n\n");

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);

	printf("\n\nafter\n\n");
	return (0);
}
