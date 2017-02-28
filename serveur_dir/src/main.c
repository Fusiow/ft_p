/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:52:59 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:53:01 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include "server.h"

void					set_error(char *function, char *message, char *wbuf)
{
	perror(function);
	ft_strcpy(wbuf, message);
}

void					success_getfile(size_t size, char *filename)
{
	printf("<== [%zu bytes received]\n", size);
	chmod(filename, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}

char					*set_buffer(int fd, char *wbuf, size_t *size)
{
	char				*buf;

	*size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buf = (char *)malloc(*size);
	if (!buf)
	{
		set_error("malloc", "Error - Could not malloc", wbuf);
		return (NULL);
	}
	ft_bzero(buf, *size);
	return (buf);
}

int						main(int ac, char *av[])
{
	t_server			server;

	if (ac < 2)
	{
		printf("usage: ./serveur [port]\n");
		return (0);
	}
	ft_bzero(&server, sizeof(t_server));
	create_server(ft_atoi(av[1]), &(server.sockfd));
	run_server(&server);
	return (0);
}
