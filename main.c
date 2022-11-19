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

        char ch;
        pid_t pid[6];
        
        process_t creat_event;
        creat_event.info.id=5;
        sprintf(creat_event.info.name,"proc_creat_event");
        sprintf(creat_event.info.in,"/dev/pts/%d",15);
        sprintf(creat_event.info.out,"/dev/pts/%d",16);
        creat_event.func=creat_event_func;
        pid[5]=creat_process(&creat_event);

        process_t dispatcher;
        dispatcher.info.id=0;
        sprintf(dispatcher.info.name,"proc_dispatcher");
        sprintf(dispatcher.info.in,"/dev/pts/%d",15);
        sprintf(dispatcher.info.out,"/dev/pts/%d",16);
        dispatcher.func=dispacher_fuc;
        pid[0]=creat_process(&dispatcher);
        //child ->dispatcher
        //parent ->creat event
        process_t proc[4];
        for (int i= 0; i < 4; i++)
        {            
            proc[i].info.id=i+1;
            sprintf(proc[i].info.name,"proc_child %d", i+1);
            sprintf(proc[i].info.in,"/dev/pts/%d",2*i+7);
            sprintf(proc[i].info.out,"/dev/pts/%d",2*i+8);
            proc[i].func=incremente;
            pid[i+1]=creat_process(&proc[i]);
        }
        
        
        while ( (ch = getchar()) != 'q' ) {
        sleep (1);
        }
        for(int i=0; i<6;i++){
             kill(pid[i], SIGKILL);
        }
    }
    // closing app
    DEBUG(("App exit"));
    // fclose(logptr);
    return 0;
}

