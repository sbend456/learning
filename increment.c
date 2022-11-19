#include "main.h"
#include "increment.h"
#include "process.h"

int incremente(process_info *p){
    int count = 0;
    char path[100];
    sprintf(path,"./f%d.txt",p->id);
    FILE *file=fopen(path,"wa");
    //---------PRINT PROCESS INFORMATION----------
    DEBUG(("NAME: %s ,IN: %s ,OUT: %s",\
    p->name,p->in,p->out));
    //---------
    while (count!=10)
    {
        fprintf(file,"count : %d\n", count);
        // DEBUG (("count : %d\n",count));
        fclose(file);
        fopen(path,"a");
        count++;
        sleep(p->id);
    }
    fclose(file);
    return 0;
}