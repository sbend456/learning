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
        p->info.id,p->info.name,p->info.in,p->info.out);
        p->func(&(p->info));
        exit (0);
    }
}