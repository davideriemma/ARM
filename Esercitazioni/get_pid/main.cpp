#include <iostream>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    std::cout << "The pid of the process is: " << static_cast<int>(getpid()) << std::endl;

    return 0;
}