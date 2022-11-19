#include "main.h"
#include "event.h"
#include "process.h"
#include "mail.h"

// extern process_t proc[4];
char dev_in[4][20]={"/dev/pts/2" , "/dev/pts/4","/dev/pts/6", "/dev/pts/8"};

int dispacher_fuc(process_info *p){
    DEBUG(("dispatch started"));
    int count=1;
    while (1)
    {
        //recevoir evenemt
        OBJECT *obj_ptr=receive(p->out);
        DEBUG(("Dispatcher RCV DEPART : %d",obj_ptr->event.department));
        // DEBUG(("departement:") );
        // DEBUG(("departement: %d",obj_ptr->event.department) );
        // DEBUG(("sending to : %s",.));
        //verifier departemt de event
        // send(proc[0].info.in,obj_ptr);
        //envoyer au bn process
        sleep(1);
        DEBUG(("dispacher %d", count++));
    } 

    
}
