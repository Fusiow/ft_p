/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:50:02 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:50:07 by rkharif          ###   ########.fr       */
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

void		print_error(char *function, char *message)
{
	perror(function);
	printf("%s\n", message);
}

void		treat_command(int sockfd, char *cmd)
{
	if (ft_strncmp(cmd, "quit", 4) == 0)
		execute_quit(sockfd);
	else if (ft_strncmp(cmd, "ls", 2) == 0)
		execute_ls(sockfd, cmd);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		execute_cd(sockfd, cmd);
	else if (ft_strncmp(cmd, "get", 3) == 0)
		execute_get(sockfd, cmd);
	else if (ft_strncmp(cmd, "put", 3) == 0)
		execute_put(sockfd, cmd);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		execute_pwd(sockfd);
	else if (cmd[0])
		execute_none(sockfd);
}

int			send_message(int sockfd, char *wbuf)
{
	int		numbytes;

	if ((numbytes = send(sockfd, wbuf, MAX_DATA_SIZE, 0)) < 0)
	{
		perror("send");
		printf("Could not send message\n");
		return (-1);
	}
	printf("==> %s\n", wbuf);
	return (0);
}

void		recv_message(int sockfd)
{
	int		numbytes;
	char	rbuf[MAX_DATA_SIZE + 1];

	ft_bzero(rbuf, MAX_DATA_SIZE + 1);
	if ((numbytes = recv(sockfd, rbuf, MAX_DATA_SIZE, 0)) < 0)
	{
		perror("recv");
		printf("Could not receive message\n");
		return ;
	}
	printf("<== %s\n", rbuf);
}

int			get_file_size(int sockfd)
{
	int		numbytes;
	char	rbuf[MAX_DATA_SIZE + 1];

	ft_bzero(rbuf, MAX_DATA_SIZE + 1);
	if ((numbytes = recv(sockfd, rbuf, MAX_DATA_SIZE, 0)) < 0)
	{
		perror("recv");
		printf("Could not receive message\n");
		return (0);
	}
	printf("<== %s\n", rbuf);
	if (ft_strncmp(rbuf, "Success", 7) == 0)
		return (ft_atoi(&rbuf[10]));
	return (-1);
}
