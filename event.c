#include "main.h"
#include "event.h"
#include "process.h"
#include "mail.h"


OBJECT * start_list=0;
OBJECT * last=0;
int count=0;

//=======================================

static char *rand_string(char *str, size_t size)
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
    return str;
}

OBJECT * new_event(void){
    OBJECT* elemt;
    elemt = malloc(sizeof (OBJECT));
    elemt->event.num=++count;
    elemt->event.department = (rand()%4);
     DEBUG(("new event depart : %d",elemt->event.department));
    rand_string(elemt->event.text, 50);
    elemt->next=NULL;   
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
    while(1){
        OBJECT * event;    
        printf("Generate Event %d\n", i++);
        // printf("in event %s\n", p->in);
        event =new_event();
        DEBUG(("creat event depart: %d",event->event.department));
        send(p->in,event);
        sleep(5);
    }
    return 0;
}


