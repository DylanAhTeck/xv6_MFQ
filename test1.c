//#include <stdio.h>
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{

    int n = 3;
    int id;

    printf(1, "~~~~~~~~~~~~~~~~~~ Test 1 ~~~~~~~~~~~~~~~~~~\n");

    for (int k = 0; k < n; k++)
    {
        id = fork();
        if (id < 0)
        {
            printf(1, "%d failed in fork!\n", getpid());
        }
        else if (id > 0)
        { //parent
            printf(1, "Parent %d creating child  %d\n", getpid(), id);
            wait();
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
            printf(1, "write return %d\n", j);
            close(fd);
        }
        else
        { // child
            printf(1, "Child %d created\n", getpid());
            printf(1, "Child running Computation intensive task");
            int x;
            //Computation intensive

            for (int i = 0; i < 10000; i++)
            {
                x = x + 3.14 * 89.64; // useless calculations to consume CPU time
            }
        }
    }

    //Print info
    printf(1, "%d", getpinfo(getpid()));

    exit();
}
