//#include <stdio.h>
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{

    int id;

    printf(1, "~~~~~~~~~~~~~~~~~~ Test 1 ~~~~~~~~~~~~~~~~~~\n");

    //printf(1, "%d", getpinfo(getpid()));
    id = fork();

    if (id < 0)
    {
        printf(1, "%d failed in fork!\n", getpid());
    }

    else if (id > 0)
    { //parent

        //printf(1, "Parent %d creating child  %d\n", getpid(), id);

        //IO intensive
        printf(1, "Parent running I/O intensive task");

        char *filename = "testIO.txt";
        int fd;
        int j;

        fd = open(filename, O_CREATE | O_WRONLY);
        if (fd == -1)
        {
            printf(1, "Error! Could not open file\n");
            return -1;
        }

        for (int i = 0; i < 10; i++)
        {
            j = write(fd, "A", 1);
        }
        if (j != 1)
            printf(1, "Error in writing to file\n");
        printf(1, "Parent completed\n");

        close(fd);
        wait();

        getpinfo(0);
    }

    else
    { // child

        printf(1, "Child %d created\n", getpid());
        printf(1, "Child running computation intensive task\n");
        //int x;

        int x = 999999999;
        //Computation intensive

        //Long running CPU bound process
    for (double z = 0; z < 20000000; z += 1)
    {
        x = x / 1.2; // useless calculations to consume CPU time
    }

        /*
        for (int i = 0; i < 100000; i++)
        {
            x = x + 3.14 * 89.64; // useless calculations to consume CPU time
        }*/
        printf(1, "Child completed\n");
    }

    exit();
}