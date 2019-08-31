/*
** EPITECH PROJECT, 2019
** jona
** File description:
** joan
*/

#ifndef FTP_H_
#define FTP_H_
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <errno.h>

int fd_server;
int fd_client;
int usr;

typedef struct list_s
{
    char *username;
    void (*lst)(char *data);
    int log;

}   list_t;

void getUser(char *data);
void getPassword(char *data);
void getOut(char *data);
void create_dir(char *data);
void my_chdir(char *data);
void chdir_back(char *data);
void my_pwd(char *data);
void check_dir(char *buff);
void chdir_back(char *data);
char *replace_r(char *buff);
char *replace_n(char *buff);
char *init_bzero(char *buff);
void parse_everything(char *data, int i);
void check_if_valid(char *data, bool valid);
void remove_delim(char *buff);
void close_free(char *buff2, FILE *file);
int read_lines(void);
void my_socket(void);
void my_socketopt(void);
void my_bind(int port);
void my_listen(void);
void my_rm(char *data);
void my_rmdir(char *data);
#endif
