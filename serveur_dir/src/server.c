/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:53:14 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:53:16 by rkharif          ###   ########.fr       */
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

void					create_server(int port, int *sockfd)
{
	struct sockaddr_in	s_addr;

	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(-1);
	}
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(port);
	s_addr.sin_addr.s_addr = INADDR_ANY;
	ft_bzero(&(s_addr.sin_zero), 8);
	if (bind(*sockfd, (struct sockaddr*)&s_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("bind");
		exit(-2);
	}
	if (listen(*sockfd, BACKLOG) < 0)
	{
		perror("listen");
		exit(-3);
	}
	printf("Server listening on port %d... (Press ^C to interrupt)\n", port);
}

void					destroy_server(t_server *server)
{
	int					i;

	i = 0;
	while (i < MAX_CLIENTS)
	{
		if (server->clients[i])
			close(server->clients[i]);
		i++;
	}
	close(server->sockfd);
	exit(0);
}

void					reset_server(t_server *server)
{
	int					i;

	server->tv.tv_sec = 0;
	server->tv.tv_usec = 0;
	FD_ZERO(&(server->readfds));
	FD_ZERO(&(server->writefds));
	i = 0;
	while (i < MAX_CLIENTS)
	{
		if (server->clients[i] != 0)
		{
			FD_SET(server->clients[i], &(server->readfds));
			FD_SET(server->clients[i], &(server->writefds));
		}
		i++;
	}
	FD_SET(server->sockfd, &(server->readfds));
}

void					run_server(t_server *server)
{
	int					over;

	server->sin_size = sizeof(struct sockaddr_in);
	ft_bzero(server->clients, MAX_CLIENTS * sizeof(int));
	server->ndfs = server->sockfd;
	getcwd(server->i_pwd, 255);
	ft_strcpy(server->c_pwd, server->i_pwd);
	over = 0;
	while (!over)
	{
		reset_server(server);
		if (select(server->ndfs + 1, &(server->readfds), &(server->writefds),
			NULL, &(server->tv)) >= 0)
		{
			if (FD_ISSET(server->sockfd, &(server->readfds)))
				handle_connection(server);
			handle_io(server);
		}
		else
		{
			perror("select");
			over = 1;
		}
	}
}
