/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:52:48 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:52:50 by rkharif          ###   ########.fr       */
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

void		execute_ls_child(char *wbuf, int link[2], char *rbuf)
{
	ft_strcpy(wbuf, "Success - ls");
	dup2(link[1], STDOUT_FILENO);
	close(link[0]);
	close(link[1]);
	if (rbuf[1])
		execl("/bin/ls", "ls", &rbuf[1], 0);
	else
		execl("/bin/ls", "ls", 0);
	exit(0);
}

void		execute_ls_parent(char *wbuf, int link[2])
{
	int		numbytes;

	close(link[1]);
	if ((numbytes = read(link[0], wbuf, MAX_DATA_SIZE)) < 0)
	{
		perror("read");
		ft_strcpy(wbuf, "Error - Could not read");
	}
	wait(NULL);
}

void		execute_ls(t_server *server, int client, char *rbuf)
{
	pid_t	pid;
	int		link[2];
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	if (pipe(link) < 0)
	{
		perror("pipe");
		ft_strcpy(wbuf, "Error - Could not pipe stdout");
		send_message(server, client, wbuf);
		return ;
	}
	pid = fork();
	if (pid == 0)
		execute_ls_child(wbuf, link, rbuf);
	else if (pid > 0)
		execute_ls_parent(wbuf, link);
	else
	{
		perror("fork");
		ft_strcpy(wbuf, "Error - Could not fork");
	}
	send_message(server, client, wbuf);
}

void		execute_cd(t_server *server, int client, char *rbuf)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	if (!rbuf[1])
		ft_strcpy(&rbuf[1], getenv("HOME"));
	if (chdir(&rbuf[1]) < 0)
	{
		perror("chdir");
		ft_strcpy(wbuf, "Error - Could not chdir");
	}
	else
	{
		getcwd(server->r_pwd, 255);
		if (ft_strlen(server->r_pwd) < ft_strlen(server->i_pwd))
		{
			ft_strcpy(wbuf, "Error - Requested path is above initial path");
			chdir(server->c_pwd);
		}
		else
		{
			ft_strcpy(server->c_pwd, server->r_pwd);
			ft_strcpy(wbuf, "Success - cd");
		}
	}
	send_message(server, client, wbuf);
}

void		execute_pwd(t_server *server, int client)
{
	char	wbuf[MAX_DATA_SIZE + 1];

	ft_bzero(wbuf, MAX_DATA_SIZE + 1);
	ft_strcpy(wbuf, server->c_pwd);
	send_message(server, client, wbuf);
}
