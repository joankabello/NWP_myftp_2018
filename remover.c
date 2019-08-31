/*
** EPITECH PROJECT, 2019
** j
** File description:
** j
*/

#include "ftp.h"

void my_rm(char *data)
{
    char *buff = strtok(data, " ");
    buff = strtok(NULL, " ");

    if (unlink(buff) == 0)
        dprintf(fd_client, "250\r\n");
    else if (unlink(buff) == EACCES)
        dprintf(fd_client, "550\r\n");
    else
        dprintf(fd_client, "550\r\n");
}

void my_rmdir(char *data)
{
    char *buff = strtok(data, " ");
    buff = strtok(NULL, " ");

    if (rmdir(buff) == 0)
        dprintf(fd_client, "250\r\n");
    else
        dprintf(fd_client, "550\r\n");
}