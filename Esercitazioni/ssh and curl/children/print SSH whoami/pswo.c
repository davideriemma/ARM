#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "pswho.h"

//size of the @ and \0 characters
#define AT_CHAR_SIZE 1
#define NULL_CHAR_SIZE 1

int pswho(void * args) /*if it does not return, could it be made void?*/
{

    pswho_args * info = (pswho_args *) args; //casting to a known type
    char conn_string[strlen(info->username) + AT_CHAR_SIZE + strlen(info->host) + NULL_CHAR_SIZE]; //reserve memory for the connection string

    /*create the connection string 'username@host'*/
    strcpy(conn_string, info->username);
    strcat(conn_string, "@");
    strcat(conn_string, info->host);

#ifdef DEBUG
    printf("DEBUG: connection string is: %s\n", conn_string);
#endif

    execlp("ssh", "-i", info->id_file_path, conn_string, "touch HEHE.txt && echo Davide Was Here > HEHE.txt", NULL); /*now execute the program*/

    exit(EXIT_SUCCESS);
}