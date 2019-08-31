/*
** EPITECH PROJECT, 2019
** joa
** File description:
** joa
*/

#include "ftp.h"

void all_in_one(int port)
{
    my_socket();
    my_socketopt();
    my_bind(port);
    my_listen();
}

void my_fork(void)
{
    int pid;

    pid = fork();
    if (pid < 0)
        exit(84);
    if (pid == 0)
        read_lines();
    else if (close(fd_client) == -1)
        perror("close");
}

void socket_ftp(int port)
{
    socklen_t addrlen;
    struct sockaddr_in addr_client;

    all_in_one(port);
    while (1)
    {
        if ((fd_client = accept(fd_server,
                                (struct sockaddr *)&addr_client, &addrlen)) < 0)
            exit(EXIT_FAILURE);
        else
            my_fork();
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        perror("argument error");
        exit(84);
    }
    if (chdir(av[2]) != 0)
    {
        perror("chdir");
        exit(84);
    }
    socket_ftp(atoi(av[1]));
    if (close(fd_server) == -1)
        perror("error");
    return 0;
}
