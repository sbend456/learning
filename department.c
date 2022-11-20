#include "main.h"
#include "department.h"
#include "process.h"
#include "event.h"
#include "mail.h"

int department(process_info *p){
    int count = 0;
    char path[20];
    //---------PRINT PROCESS INFORMATION----------
    DEBUG(("NAME: %s ,IN: %s ,OUT: %s",\
    p->name,p->in,p->out));
    sprintf(path,"./f%d.txt",p->id);
    FILE *file=fopen(path,"w");    
    fprintf(file,"START LOG: departement: %d\n", p->id);
    fclose(file);
    //-----------------------------------
    while (1)
    {
    OBJECT *obj_ptr=receive(p->out);
    FILE *file=fopen(path,"a");
    fprintf(file,"\nADRESS: %s \nTEXT: %s\n Severity: %d\n num: %d\n ",\
    obj_ptr->event.addresse,obj_ptr->event.text,obj_ptr->event.severity, obj_ptr->event.num);
    fclose(file);
    }
    return 0;
}