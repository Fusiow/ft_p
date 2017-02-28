/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:49:37 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:49:45 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include "client.h"

void					create_client(in_addr_t addr, int port, int *sockfd)
{
	struct sockaddr_in	s_addr;

	if ((*sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(-1);
	}
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = ntohs(port);
	s_addr.sin_addr.s_addr = addr;
	if (connect(*sockfd, (struct sockaddr *)&s_addr, sizeof(s_addr)) < 0)
	{
		perror("connect");
		exit(-2);
	}
}

void					destroy_client(int client)
{
	close(client);
	exit(0);
}

void					run_client(int sockfd)
{
	int					over;
	int					n;
	char				cmd[MAX_DATA_SIZE + 1];

	over = 0;
	while (!over)
	{
		ft_putstr("$> ");
		ft_bzero(cmd, MAX_DATA_SIZE + 1);
		if ((n = read(0, cmd, MAX_DATA_SIZE)) < 0)
			perror("read");
		else
		{
			simplify(cmd, n);
			treat_command(sockfd, cmd);
		}
	}
}
