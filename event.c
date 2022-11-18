#include "main.h"
#include "event.h"


OBJECT * start_list=0;
OBJECT * last=0;

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
    elemt->event.department = (rand()%4);
    rand_string(elemt->event.text, 50);
    elemt->next=NULL;   
    if(start_list == NULL){
        start_list = elemt;
    }else{
        // last->next = elemt;
    }
    last = elemt;
    return elemt;
}

void creat_event(){
    int i=0;
    while(1){
        OBJECT * event;    
        int deprt;
        char device[20];
        int in;
        printf("Generate Event %d\n", i++);
        event =new_event();
        in = 2*(event->event.department)+1;
        sprintf(device, "/dev/pts/%d", in);
        printf("DEVICE: %s\n", device);
        // send(device,"EVENT\n");
        sleep(5);
    }

}
