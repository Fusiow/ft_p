/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:50:18 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:50:25 by rkharif          ###   ########.fr       */
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

void		send_file(int sockfd, char *buf, size_t size)
{
	int		numbytes;

	if ((numbytes = send(sockfd, buf, size, 0)) < 0)
	{
		perror("send");
		printf("Could not send file\n");
		return ;
	}
	printf("==> [%zu bytes sent]\n", size);
}

void		execute_none(int sockfd)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, ft_itoa(CMD_NONE));
	if (send_message(sockfd, wbuf) == 0)
		recv_message(sockfd);
}

void		execute_quit(int sockfd)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, ft_itoa(CMD_QUIT));
	if (send_message(sockfd, wbuf) == 0)
		recv_message(sockfd);
	destroy_client(sockfd);
	exit(0);
}

void		execute_ls(int sockfd, char *cmd)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, ft_itoa(CMD_LS));
	if (cmd[3])
		ft_strcpy(&wbuf[1], &cmd[3]);
	if (send_message(sockfd, wbuf) == 0)
		recv_message(sockfd);
}

void		execute_cd(int sockfd, char *cmd)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, ft_itoa(CMD_CD));
	if (cmd[3])
		ft_strcpy(&wbuf[1], &cmd[3]);
	if (send_message(sockfd, wbuf) == 0)
		recv_message(sockfd);
}
