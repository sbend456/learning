#include "main.h"
#include "event.h"
#include "process.h"
#include "mail.h"

extern int init_device_nr;
extern int step_device;

OBJECT * start_list=0;
OBJECT * last=0;
int count=0;

//=======================================

void rand_string(char *str, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK...";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
}

OBJECT * new_event(void){
    OBJECT* elemt;
    elemt = malloc(sizeof (OBJECT));
    elemt->event.num=++count;
    DEBUG(("COUNT:%d", elemt->event.num));
    elemt->event.department = (rand()%4);
     DEBUG(("new event depart : %d",elemt->event.department));
    rand_string(elemt->event.text,(rand()%MAX_TXT_SIZE));
    rand_string(elemt->event.addresse,(rand()%MAX_ADDRESS_SIZE));
    elemt->event.severity=(rand()%10);
    elemt->next=NULL; 
    DEBUG(("GENERATED EVENT: ADRESS: %s TEXT: %s Severity: %d num: %d department: %d",\
    elemt->event.addresse,elemt->event.text,elemt->event.severity, elemt->event.num, elemt->event.department));
  
    if(start_list == NULL){
        start_list = elemt;
    }else{
        last->next=(EVENT_TYPE*)elemt;
        // last->next = elemt;
    }
    last = elemt;
    return elemt;
}

int creat_event_func(process_info *p){
    int i=0;
    char dispatch_dev[20];
    sprintf(dispatch_dev, "/dev/pts/%d", step_device* DISPATCH + init_device_nr);
    while(1){
        OBJECT * event;    
        DEBUG(("Generate Event %d\n", i++));
        event =new_event();
        DEBUG(("creat event depart: %d",event->event.department));
        DEBUG(("PIPE IN %d %d %s",init_device_nr, step_device, dispatch_dev));
        send(dispatch_dev,event);
        sleep(5);
    }
    return 0;
}


