#include "main.h"
#include "event.h"

int dispacher_fuc(int i){
    int count=1;
    while (1)
    {
        
        sleep(1);
        DEBUG(("dispacher %d", count++));
    } 
    
}
