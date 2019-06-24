//#include <stdio.h>
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{

    //int id;
    int x = 999999999;

    printf(1, "~~~~~~~~~~~~~~~~~~ Test 2 ~~~~~~~~~~~~~~~~~~\n");

    printf(1, "Running long computational task");

    //Long running CPU bound process
    for (double z = 0; z < 20000000; z += 1)
    {
        x = x / 1.2; // useless calculations to consume CPU time
    }

    getpinfo(0);
    exit();
}