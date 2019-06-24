#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{

    int n = 1000;

    printf(1, "~~~~~~~~~~~~~~~~~~ Test 3 ~~~~~~~~~~~~~~~~~~\n");
    for (int k = 0; k < n; k++)
    {
        sleep(1);
    }

    //Print info
    getpinfo(0);
    //printf(1, getpinfo(getpid()));
    exit();
}