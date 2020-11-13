#include "children.h"

/*defining the vector of child functions to be executed*/

int (*threads[])(void *) = {bm, pswho}; //the return value shall become 'void' next time