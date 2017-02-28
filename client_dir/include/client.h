/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkharif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 10:51:10 by rkharif           #+#    #+#             */
/*   Updated: 2017/02/28 10:51:13 by rkharif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define MAX_DATA_SIZE 8192

# define CMD_NONE 0
# define CMD_QUIT 1
# define CMD_LS 2
# define CMD_CD 3
# define CMD_GET 4
# define CMD_PUT 5
# define CMD_PWD 6

typedef struct			s_dirty
{
	char				wbuf[MAX_DATA_SIZE + 1];
	char				*buf;
	int					fd;
	size_t				size;
	int					numbytes;
}						t_dirty;

/*
** main.c
*/
void					success_getfile(int size, char *filename);
void					simplify(char *s, int n);
/*
** client.c
*/
void					create_client(in_addr_t addr, int port, int *sockfd);
void					destroy_client(int client);
void					run_client(int sockfd);

/*
** command.c
*/
void					print_error(char *function, char *message);
void					treat_command(int sockfd, char *cmd);
int						send_message(int sockfd, char *wbuf);
void					recv_message(int sockfd);
int						get_file_size(int sockfd);

/*
** command2.c
*/
void					send_file(int sockfd, char *buf, size_t size);
void					execute_none(int sockfd);
void					execute_quit(int sockfd);
void					execute_ls(int sockfd, char *cmd);
void					execute_cd(int sockfd, char *cmd);

/*
** command3.c
*/
void					execute_get(int sockfd, char *cmd);
void					put_file(int sockfd, t_dirty a);
void					recv_file(int sockfd, int size, char *filename);
void					execute_put(int sockfd, char *cmd);
void					execute_pwd(int sockfd);

#endif
