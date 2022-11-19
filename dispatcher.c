#include "main.h"
#include "event.h"
#include "process.h"
#include "mail.h"

extern process_t proc[4];

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
    
        //verifier departemt de event
        send(proc[0].info.out,obj_ptr);
        //envoyer au bn process
        sleep(1);
        DEBUG(("dispacher %d", count++));
    } 

    
}
