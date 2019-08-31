/*
** EPITECH PROJECT, 2019
** joan
** File description:
** joan
*/

#ifndef LIST_H_
#define LIST_H_

static list_t ls[] = {
    {"USER", &getUser, 0},
    {"PASS", &getPassword, 0},
    {"QUIT", &getOut, 0},
    {"MKD", &create_dir, 1},
    {"CWD", &my_chdir, 1},
    {"CDUP", &chdir_back, 1},
    {"PWD", &my_pwd, 1},
    {"DELE", &my_rm, 1},
    {"RMD", &my_rmdir, 1},
    {NULL, NULL, 0}};

#endif