/*
** EPITECH PROJECT, 2019
** joan
** File description:
** oan
*/

#include "ftp.h"
#include "list.h"

char *init_bzero(char *buff)
{
    replace_r(buff);
    replace_n(buff);
    return (buff);
}

void parse_everything(char *data, int i)
{
    if (ls[i].log == 1 && usr != 2)
        dprintf(fd_client, "530 Error loging in.\r\n");
    else {
        ls[i].lst(data);
    }
}

void check_if_valid(char *data, bool valid)
{
    if (valid == false)
        dprintf(fd_client, "500 Invalid command\r\n");
    free(data);
}

void remove_delim(char *buff)
{
    bool valid = false;
    buff = init_bzero(buff);
    char *data = strdup(buff);
    char *parse = strtok(buff, " ");
    for (int i = 0; ls[i].lst; i++) {
        if (parse != NULL && strcmp(parse, ls[i].username) == 0) {
            parse_everything(data, i);
            valid = true;
        }
    }
    check_if_valid(data, valid);
}

void close_free(char *buff2, FILE *file)
{
    free(buff2);
    fclose(file);
    if (fcntl(fd_client, F_GETFD) != -1)
        close(fd_client);
}
