/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:50:38 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:50:41 by rkharif          ###   ########.fr       */
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

void		execute_get(int sockfd, char *cmd)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, ft_itoa(CMD_GET));
	if (!cmd[4])
	{
		printf("usage: get [file]\n");
		return ;
	}
	ft_strcpy(&wbuf[1], &cmd[4]);
	if (send_message(sockfd, wbuf) == 0)
		recv_file(sockfd, get_file_size(sockfd), &wbuf[1]);
}

void		put_file(int sockfd, t_dirty a)
{
	ft_bzero(a.buf, a.size);
	ft_strcpy(&a.wbuf[ft_strlen(a.wbuf)], ft_itoa(a.size));
	if ((a.numbytes = read(a.fd, a.buf, a.size)) < 0)
		print_error("read", "Could not read file");
	else
	{
		if (send_message(sockfd, a.wbuf) == 0)
		{
			send_file(sockfd, a.buf, a.size);
			recv_message(sockfd);
		}
	}
	free(a.buf);
}

void		recv_file(int sockfd, int size, char *filename)
{
	int		numbytes;
	char	*buf;
	int		fd;

	if (size < 0)
		return ;
	buf = (char *)malloc(size);
	if (!buf)
		print_error("malloc", "Could not malloc");
	else
	{
		recv(sockfd, buf, size, 0);
		if ((fd = open(filename, O_RDWR | O_CREAT | O_TRUNC)) < 0)
			print_error("open", "Could not create file");
		else
		{
			if ((numbytes = write(fd, buf, size)) < 0)
				print_error("write", "Could not write to file");
			else
				success_getfile(size, filename);
			close(fd);
		}
		free(buf);
	}
}

void		execute_put(int sockfd, char *cmd)
{
	t_dirty	a;

	ft_bzero(a.wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(a.wbuf, ft_itoa(CMD_PUT));
	if (!cmd[4])
	{
		printf("usage: put [file]\n");
		return ;
	}
	ft_strcpy(&a.wbuf[1], &cmd[4]);
	ft_strcpy(&a.wbuf[ft_strlen(a.wbuf)], "\n");
	if ((a.fd = open(&cmd[4], O_RDONLY)) < 0)
		print_error("open", "Could not open file");
	else
	{
		a.size = lseek(a.fd, 0, SEEK_END);
		lseek(a.fd, 0, SEEK_SET);
		a.buf = (char *)malloc(a.size);
		if (!a.buf)
			print_error("malloc", "Could not malloc");
		else
			put_file(sockfd, a);
		close(a.fd);
	}
}

void		execute_pwd(int sockfd)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, ft_itoa(CMD_PWD));
	if (send_message(sockfd, wbuf) == 0)
		recv_message(sockfd);
}
