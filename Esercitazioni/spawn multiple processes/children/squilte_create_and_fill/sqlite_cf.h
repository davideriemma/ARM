#ifndef SQLITE_CF_H_
#define SQLITE_CF_H_

typedef struct 
{
    char * dbname;
    char * dbquery;
}sqlite_cf_args;


int sqlite_cf(void * args);

#endif