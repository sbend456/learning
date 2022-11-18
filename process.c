#include "main.h"
#include "increment.h"
#include "process.h"

void creat_process(process_t *p)
{
    pid_t process;
    process = fork();
    
    if (process < 0)
    {
        printf("ERROR FORK\n");
        exit(1);
    }
    if (process == 0)
    {
        printf("\nchild: %d\nname: %s\nIN: %s\nOUT: %s\n",\
        p->id,p->name,p->in,p->out);
        p->func(p->id);
        exit (0);
    }
}