#include "main.h"
#include "event.h"
#include "process.h"

int dispacher_fuc(process_info *p){
    DEBUG(("dispatch started"))
    int count=1;
    while (1)
    {
        //recevoir evenemt
        OBJECT *obj_ptr;
        receive(p->out,&obj_ptr);
        // DEBUG(("departement:") );
        DEBUG(("departement: %d",obj_ptr->event.department) );
       
        //verifier departemt de event
        //depart=pointeur sur le depart de lobj
        // switch (obj_ptr->event.department)
        // {
        // case 0:
        //     break;
        // case 1:
        // /* code */
        // break;
        // case 2:
        //     /* code */
        //     break;
        // case 3:
        // /* code */
        // break;
    
        // default:
        //     break;
        // }
        //envoyer au bn process
        sleep(1);
        DEBUG(("dispacher %d", count++));
    } 

    
}
