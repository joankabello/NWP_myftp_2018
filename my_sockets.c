/*
** EPITECH PROJECT, 2019
** joan
** File description:
** joan
*/

#include "ftp.h"

int read_lines(void)
{
    dprintf(fd_client, "220 Service ready for new user.\r\n");
    FILE *file = fdopen(dup(fd_client), "r");
    char *buff2 = NULL;
    size_t i = 0;

    while (1) {
        if (getline(&buff2, &i, file) == -1) {
            fclose(file);
            free(buff2);
        }
        fprintf(stderr, "%s", buff2);
        remove_delim(buff2);
        if (strcmp(buff2, "QUIT") == 0 )
            break;
    }
    close_free(buff2, file);
    exit (0);
}

void my_socket(void)
{
    struct protoent *pro;

    if ((pro = getprotobyname("TCP")) == NULL) {
        perror("getprotobyname");
        exit(84);
    }
    if ((fd_server = socket(AF_INET, SOCK_STREAM, pro->p_proto)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
}

void my_socketopt(void)
{
    int opt;

    opt = 1;
    if (setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
}

void my_bind(int port)
{
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = ntohs(port);
    if (bind(fd_server, (const struct sockaddr *)&address,
             sizeof(address)) < 0)
        exit(EXIT_FAILURE);
}

void my_listen(void)
{
    if (listen(fd_server, 100) < 0)
        exit(EXIT_FAILURE);
}
