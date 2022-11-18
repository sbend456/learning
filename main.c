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
        for (int i= 0; i < 4; i++)
        {
            
            proc[i].id=i+1;
            sprintf(proc[i].name,"proc_child %d", i+1);
            // printf("name %s\n",proc[i].name);
            sprintf(proc[i].in,"/dev/pts/%d",2*i+1);
            // printf("in %s\n",proc[i].in);
            sprintf(proc[i].out,"/dev/pts/%d",2*i+2);
            // printf("out %s\n",proc[i].out);
            proc[i].func=incremente;
            creat_process(&proc[i]);
        }
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

