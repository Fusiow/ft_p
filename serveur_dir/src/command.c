/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:52:35 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:52:39 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include "server.h"

void		send_message(t_server *server, int client, char *wbuf)
{
	int		numbytes;

	if (FD_ISSET(client, &(server->writefds)))
	{
		if (wbuf[ft_strlen(wbuf) - 1] == '\n')
			wbuf[ft_strlen(wbuf) - 1] = '\0';
		if ((numbytes = send(client, wbuf, MAX_DATA_SIZE, 0)) < 0)
			printf("Could not send message: %s\n", wbuf);
		else
			printf("==> %s\n", wbuf);
	}
}

void		execute_none(t_server *server, int client)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, "Error - Command not found");
	send_message(server, client, wbuf);
}

void		execute_quit(t_server *server, int client)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, "Success - Quitting");
	send_message(server, client, wbuf);
	destroy_server(server);
}

void		execute_get(t_server *server, int client, char *rbuf)
{
	t_dirty	a;

	a.numbytes = -1;
	ft_bzero(a.wbuf, MAX_DATA_SIZE + 1);
	if ((a.fd = open(&rbuf[1], O_RDONLY)) < 0)
		set_error("open", "Error - Could not open file", a.wbuf);
	else
	{
		if ((a.buf = set_buffer(a.fd, a.wbuf, &a.size)))
		{
			if ((a.numbytes = read(a.fd, a.buf, a.size)) < 0)
				set_error("read", "Error - Could no read file", a.wbuf);
			else
			{
				ft_strcpy(a.wbuf, "Success - ");
				ft_strcpy(&(a.wbuf[10]), ft_itoa(a.size));
				send_message(server, client, a.wbuf);
				send_file(server, client, a.buf, a.size);
			}
			free(a.buf);
		}
		close(a.fd);
	}
	if (a.numbytes < 0)
		send_message(server, client, a.wbuf);
}

void		execute_put(t_server *server, int client, char *rbuf)
{
	t_file	file;
	char	wbuf[MAX_DATA_SIZE + 1];
	int		i;

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_bzero(file.filename, 256);
	i = 0;
	while (rbuf[i] && rbuf[i] != '\n')
		i++;
	i++;
	file.size = ft_atoi(&rbuf[i]);
	ft_strncpy(file.filename, &rbuf[1], i - 2);
	file.buf = (char *)malloc(file.size);
	if (!file.buf)
	{
		perror("malloc");
		ft_strcpy(wbuf, "Error - Could not malloc");
		send_message(server, client, wbuf);
		return ;
	}
	ft_bzero(file.buf, file.size);
	recv_file(server, client, file, wbuf);
	free(file.buf);
}
