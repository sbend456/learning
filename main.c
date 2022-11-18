#include "main.h"
#include "increment.h"
#include "process.h"

FILE *logptr;

void _debug(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(logptr, fmt, args);
    va_end(args);
}

// main function
int main(int argc, char **argv)
{
    int i;
    int count;
    logptr = fopen("debug.txt", "w");
    fclose(logptr);
    DEBUG(("App Started Arg count:%d", argc));
    for (i = 0; i < argc; i++)
    {
        DEBUG(("Arg %d: %s", i, argv[i]));
    }
    // implement your code here
    {
        process_t proc[4];
        // for (int j = 0; j < 4; j++)
        // {
            int j=0;
            proc[i].id=j+1;
            sprintf(proc[i].name,"process child %d", j+1);
            sprintf(proc[i].in,"/dev/pts/%d",2*j+1);
            sprintf(proc[i].out,"/dev/pts/%d",2*j+2);
            proc[i].func=incremente;
            creat_process(&proc[j]);
        // }
        int count = 0;
        while (1)
        {
            printf("counter: %d\n", count++);
            sleep(1);
        }
    }
    // closing app
    DEBUG(("App exit"));
    // fclose(logptr);
    return 0;
}

