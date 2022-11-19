#include "main.h"
#include "increment.h"
#include "process.h"
#include "event.h"
#include "dispatcher.h"

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

        process_t dispatcher;
        dispatcher.info.id=0;
        sprintf(dispatcher.info.name,"proc_dispatcher");
        sprintf(dispatcher.info.in,"/dev/pts/%d",16);
        sprintf(dispatcher.info.out,"/dev/pts/%d",17);
        dispatcher.func=dispacher_fuc;
        creat_process(&dispatcher);
        //child ->dispatcher
        //parent ->creat event
        process_t proc[4];
        for (int i= 0; i < 4; i++)
        {
            proc[i].info.id=i+1;
            sprintf(proc[i].info.name,"proc_child %d", i+1);
            sprintf(proc[i].info.in,"/dev/pts/%d",3*i+4);
            sprintf(proc[i].info.out,"/dev/pts/%d",3*i+5);
            proc[i].func=incremente;
            creat_process(&proc[i]);
        }
        
        creat_event(&dispatcher.info);
    }
    // closing app
    DEBUG(("App exit"));
    // fclose(logptr);
    return 0;
}

