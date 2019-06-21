#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{

    int n = 3;
    int id;

    printf(1, "~~~~~~~~~~~~~~~~~~ Test 2 ~~~~~~~~~~~~~~~~~~\n");
    for (int k = 0; k < n; k++)
    {
        id = fork();

        if (id < 0)
        {
            printf(1, "%d failed in fork!\n", getpid());
        }

        else if (id > 0)
        { //parent

            printf(1, "Parent running long CPU-bound task");
            wait();

            int x;
            //Long running CPU bound process
            for (int z = 0; z < 2; z += 1)
            {
                x = x + 3.14 * 89.64; // useless calculations to consume CPU time
            }
        }
        else

        { // child
            printf(1, "Child %d created\n", getpid());
            printf(1, "Child running short task");
            int x = 1000;
            int i = 0;
            while (i < x)
            {
                i += 1;
            }
        }
    }
    //Print info
    //printf(1, getpinfo(getpid()));
    exit();
}
