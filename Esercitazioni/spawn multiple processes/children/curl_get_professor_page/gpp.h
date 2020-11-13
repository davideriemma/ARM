#ifndef GPP_H_
#define GPP_H_

typedef struct
{
    char * url; //ATTENTO ALLE fregature delle stringhe
    char * retval;//ATTENTO ALLE fregature delle stringhe
} gpp_args;


int gpp(void * args);

#endif