/*
** EPITECH PROJECT, 2019
** j
** File description:
** j
*/

#include "ftp.h"

void my_chdir(char *data)
{
    char *buff = strtok(data, " ");
    buff = strtok(NULL, " ");

    if (chdir(buff) == 0)
        dprintf(fd_client, "250\r\n");
    else
        dprintf(fd_client, "550\r\n");
}

void chdir_back(char *data)
{
    if (chdir("..") == 0)
        dprintf(fd_client, "200\r\n");
    else
        dprintf(fd_client, "550\r\n");
}

void my_pwd(char *data)
{
    char *buff = NULL;
    buff = getcwd(buff, 1024);
    dprintf(fd_client, "257 %s\r\n", buff);
    free(buff);
}

char *replace_r(char *buff)
{
    if (strlen(buff) > 0 && buff[strlen(buff) - 1] == '\n')
        buff[strlen(buff) - 1] = '\0';
    return (buff);
}

char *replace_n(char *buff)
{
    if (strlen(buff) > 0 && buff[strlen(buff) - 1] == '\r')
        buff[strlen(buff) - 1] = '\0';
    return buff;
}
