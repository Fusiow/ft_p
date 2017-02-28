/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:52:12 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:52:14 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <netinet/in.h>
# include <sys/socket.h>

# define MAX_DATA_SIZE		8192
# define MAX_CLIENTS		5
# define BACKLOG			5

# define CMD_NONE			0
# define CMD_QUIT			1
# define CMD_LS				2
# define CMD_CD				3
# define CMD_GET			4
# define CMD_PUT			5
# define CMD_PWD			6

typedef struct			s_file
{
	size_t				size;
	char				*buf;
	char				filename[256];
}						t_file;

typedef struct			s_dirty
{
	int					numbytes;
	char				*buf;
	char				wbuf[MAX_DATA_SIZE + 1];
	int					fd;
	size_t				size;
}						t_dirty;

typedef struct			s_server
{
	int					sockfd;
	struct sockaddr_in	s_addr;
	int					newfd;
	int					clients[MAX_CLIENTS];
	struct sockaddr_in	c_addr;
	socklen_t			sin_size;
	int					ndfs;
	fd_set				readfds;
	fd_set				writefds;
	struct timeval		tv;
	char				i_pwd[256];
	char				c_pwd[256];
	char				r_pwd[256];
}						t_server;

/*
** main.c
*/
void					set_error(char *function, char *message, char *wbuf);
void					success_getfile(size_t size, char *filename);
char					*set_buffer(int fd, char *wbuf, size_t *size);

/*
** Server.h
*/
void					create_server(int port, int *sockfd);
void					destroy_server(t_server *server);
void					reset_server(t_server *server);
void					run_server(t_server *server);

/*
** Server2.h
*/
void					send_file(t_server *server, int client,
									char *buf, size_t size);
void					recv_file(t_server *server, int client,
									t_file file, char *wbuf);
void					handle_connection(t_server *s);
void					treat_command(t_server *server, char *rbuf, int client);
void					handle_io(t_server *s);

/*
** Command.h
*/
void					send_message(t_server *server, int client, char *wbuf);
void					execute_none(t_server *server, int client);
void					execute_quit(t_server *server, int client);
void					execute_get(t_server *serve, int client, char *rbuf);
void					execute_put(t_server *serve, int client, char *rbuf);

/*
** Command2.h
*/
void					execute_ls_child(char *wbuf, int link[2], char *rbuf);
void					execute_ls_parent(char *wbuf, int link[2]);
void					execute_ls(t_server *server, int client, char *rbuf);
void					execute_cd(t_server *server, int client, char *rbuf);
void					execute_pwd(t_server *serve, int client);

#endif
