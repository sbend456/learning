#include "main.h"
#include "event.h"
#include "process.h"


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

void creat_event(process_info *p){
    int i=0;
    while(1){
        OBJECT * event;    
        printf("Generate Event %d\n", i++);
        event =new_event();;
        send(p->in,event);
        sleep(5);
    }

}


int send(char * device, OBJECT *ptr){
    // OBJECT *ptr;&ptr;

    int fd1;
    int file1;
    char buf1;
    fd1=open(device, O_WRONLY);
    if(fd1<0){
        printf("ERROR 1 %d\n",errno);
        return 1;
    }

    DEBUG(("send event ptr: %0X",ptr));
    file1=write(fd1,&ptr,sizeof(ptr));
    if(file1<0){
        printf("error on writing: %d",errno);
        return 1;
    }
    close(fd1);
    
    return 0;
}



int receive(char *device,OBJECT **ptr){

    int fd2;
    int file2;
    // OBJECT * ptr;
    fd2=open(device,O_RDONLY);
    if(fd2<0){
        printf("ERROR on opening %s: %d\n",device, errno);
        return -1;
    }
    file2=read(fd2,ptr,sizeof(ptr));
    close(fd2);
    DEBUG(("ptr receive: %0x", *ptr));
    return 0;
}

