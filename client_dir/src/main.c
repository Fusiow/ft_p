/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:50:51 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:50:53 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netdb.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>
#include "client.h"

void					usage(void)
{
	printf("usage: ./client [machine] [port]\n");
	exit(0);
}

void					success_getfile(int size, char *filename)
{
	printf("<== [%d bytes received]\n", size);
	chmod(filename, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
}

int						simplify_loop(char *s, char *buf, int start)
{
	int					i;
	int					test;

	i = 0;
	test = 0;
	while (s[start])
	{
		if (test)
		{
			buf[i] = ' ';
			i++;
		}
		while (s[start] && (s[start] != ' ' && s[start] != '\t'))
		{
			buf[i] = s[start];
			start++;
			i++;
		}
		test = 0;
		while (s[start] && (s[start] == ' ' || s[start] == '\t'))
			start++;
		if (s[start])
			test = 1;
	}
	return (i);
}

void					simplify(char *s, int n)
{
	int					start;
	int					i;
	char				buf[MAX_DATA_SIZE + 1];

	if (!s)
		return ;
	if (s[n - 1] == '\n')
		s[n - 1] = '\0';
	else
		ft_putchar('\n');
	ft_bzero(buf, MAX_DATA_SIZE + 1);
	start = 0;
	while (s[start] && (s[start] == ' ' || s[start] == '\t'))
		start++;
	if (!s[start])
	{
		ft_bzero(s, MAX_DATA_SIZE + 1);
		return ;
	}
	i = simplify_loop(s, buf, start);
	ft_bzero(s, MAX_DATA_SIZE + 1);
	ft_memcpy(s, buf, i);
}

int						main(int ac, char *av[])
{
	int					sockfd;

	if (ac < 3)
		usage();
	if (ft_strcmp(av[1], "localhost") == 0)
		ft_strcpy(av[1], "127.0.0.1");
	create_client(inet_addr(av[1]), ft_atoi(av[2]), &sockfd);
	run_client(sockfd);
	destroy_client(sockfd);
}
