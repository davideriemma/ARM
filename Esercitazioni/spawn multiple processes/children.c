#include "children.h"

/*array delle funzioni da eseguire*/
int (*threads[])(void *) = {bm, gpp, sqlite_cf};