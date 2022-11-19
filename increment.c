#include "main.h"
#include "increment.h"
#include "process.h"
#include "event.h"
#include "mail.h"

int incremente(process_info *p){
    int count = 0;
    char path[100];
    //---------PRINT PROCESS INFORMATION----------
    DEBUG(("NAME: %s ,IN: %s ,OUT: %s",\
    p->name,p->in,p->out));
    //-----------------------------------
    OBJECT *obj_ptr=receive(p->out);
    sprintf(path,"./f%d.txt",p->id);
    FILE *file=fopen(path,"wa");
    fprintf(file,"\nADRESS: %s \ndepartement: %d \nnum: %d\n",\
    obj_ptr->event.addresse,obj_ptr->event.department, obj_ptr->event.num);

    //---------
    // while (count!=10)
    // {
    //     fprintf(file,"count : %d\n", count);
    //     // DEBUG (("count : %d\n",count));
    //     fclose(file);
    //     fopen(path,"a");
    //     count++;
    //     sleep(p->id);
    // }
    fclose(file);
    return 0;
}