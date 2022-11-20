#include "main.h"
#include "event.h"
#include "process.h"
#include "mail.h"

extern int init_device_nr;
extern int step_device;

int dispacher_fuc(process_info *p){
    char dept_dev[4][20];
    for (int i = DEPT1; i<DEPT4+1;i++){
        sprintf(dept_dev[i], "/dev/pts/%d", step_device* i + init_device_nr);
    }


    DEBUG(("dispatch started"));
    int count=1;
    while (1)
    {
        //recevoir evenemt
        OBJECT *obj_ptr=receive(p->out);
        DEBUG(("Dispatcher RCV DEPART : %d, %s",\
        obj_ptr->event.department,dept_dev[obj_ptr->event.department]));
    DEBUG(("DISPATCH RCV: ADRESS: %s TEXT: %s Severity: %d num: %d dept: %d ",\
    obj_ptr->event.addresse,obj_ptr->event.text,obj_ptr->event.severity, obj_ptr->event.num, obj_ptr->event.department+1));

        send(dept_dev[obj_ptr->event.department],obj_ptr);
        //envoyer au bn process
        DEBUG(("dispacher %d", count++));
    } 

    
}
