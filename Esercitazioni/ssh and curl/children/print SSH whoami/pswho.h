#ifndef PSWHO_H_
#define PSWHO_H_

typedef struct
{
    char * host;
    char * username;
    char * id_file_path;
}pswho_args;


int pswho(void * args);

#endif