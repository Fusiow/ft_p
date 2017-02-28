/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:53:26 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:53:28 by rkharif          ###   ########.fr       */
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

void			send_file(t_server *server, int client, char *buf, size_t size)
{
	int			numbytes;

	if (FD_ISSET(client, &(server->writefds)))
	{
		if ((numbytes = send(client, buf, size, 0)) < 0)
			printf("Could not send message: %s\n", buf);
		else
			printf("==> [%zu bytes sent]\n", size);
	}
}

void			recv_file(t_server *server, int client, t_file file, char *wbuf)
{
	int			numbytes;
	int			fd;

	if (FD_ISSET(client, &(server->readfds)))
	{
		if ((numbytes = recv(client, file.buf, file.size, 0)) < 0)
			set_error("recv", "Error - Could not recv", wbuf);
		else
		{
			if ((fd = open(file.filename, O_RDWR | O_CREAT | O_TRUNC)) < 0)
				set_error("open", "Error - Could not create file", wbuf);
			else
			{
				if ((numbytes = write(fd, file.buf, file.size)) < 0)
					set_error("write", "Error - Could not write to file", wbuf);
				else
				{
					ft_strcpy(wbuf, "Success - Received file");
					success_getfile(file.size, file.filename);
				}
				close(fd);
			}
		}
		send_message(server, client, wbuf);
	}
}

void			handle_connection(t_server *s)
{
	int			i;

	if ((s->newfd = accept(s->sockfd,
		(struct sockaddr *)&(s->c_addr), &(s->sin_size))) < 0)
	{
		perror("accept");
		return ;
	}
	printf("New connection accepted\n");
	i = -1;
	while (++i < MAX_CLIENTS)
	{
		if (s->clients[i] == 0)
		{
			s->clients[i] = s->newfd;
			break ;
		}
	}
	if (i != MAX_CLIENTS)
		s->ndfs = (s->newfd > s->ndfs) ? s->newfd : s->ndfs;
	else
	{
		printf("Connection refused, no place for new client\n");
		close(s->newfd);
	}
}

void			treat_command(t_server *server, char *rbuf, int client)
{
	if (rbuf[0] - '0' == CMD_NONE)
		execute_none(server, client);
	else if (rbuf[0] - '0' == CMD_QUIT)
		execute_quit(server, client);
	else if (rbuf[0] - '0' == CMD_LS)
		execute_ls(server, client, rbuf);
	else if (rbuf[0] - '0' == CMD_CD)
		execute_cd(server, client, rbuf);
	else if (rbuf[0] - '0' == CMD_GET)
		execute_get(server, client, rbuf);
	else if (rbuf[0] - '0' == CMD_PUT)
		execute_put(server, client, rbuf);
	else if (rbuf[0] - '0' == CMD_PWD)
		execute_pwd(server, client);
}

void			handle_io(t_server *s)
{
	int			i;
	size_t		numbytes;
	char		rbuf[MAX_DATA_SIZE + 1];

	i = 0;
	while (i < MAX_CLIENTS)
	{
		ft_bzero(rbuf, MAX_DATA_SIZE + 1);
		if (FD_ISSET(s->clients[i], &(s->readfds)))
		{
			if ((numbytes = recv(s->clients[i], rbuf, MAX_DATA_SIZE, 0)) <= 0)
			{
				close(s->clients[i]);
				s->clients[i] = 0;
				printf("Connection lost\n");
			}
			else
			{
				rbuf[numbytes] = 0;
				printf("<== %s\n", rbuf);
				treat_command(s, rbuf, s->clients[i]);
			}
		}
		i++;
	}
}
