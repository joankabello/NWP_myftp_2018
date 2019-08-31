/*
** EPITECH PROJECT, 2019
** j
** File description:
** j
*/

#include "ftp.h"

void getUser(char *data)
{
    char *buff;
    buff = strtok(data, " ");
    buff = strtok(NULL, " ");
    usr = 1;
    if (strcmp(buff, "Anonymous") == 0)
        usr = 0;
    dprintf(fd_client, "331 User name okay, need password.\r\n");
}

void getPassword(char *data)
{
    if (usr == 0) {
        usr = 2;
        dprintf(fd_client, "230 User logged in, proceed.\r\n");
    }
    else {
        dprintf(fd_client, "530\r\n");
    }
}

void getOut(char *data)
{
    printf("221\n");
    dprintf(fd_client, "221\r\n");
}

void check_dir(char *buff)
{
    if (mkdir(buff, 0755) == -1)
        dprintf(fd_client, "550 Invalid directory\r\n");
    else
        dprintf(fd_client, "257 Crated dir\r\n");
}

void create_dir(char *data)
{
    char *buff = strtok(data, " ");
    struct stat att;
    buff = strtok(NULL, " ");

    if (stat(buff, &att) == -1) {
        check_dir(buff);
    }
    else
        dprintf(fd_client, "550 Directory exists\r\n");
}
