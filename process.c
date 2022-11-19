#include "main.h"
#include "increment.h"
#include "process.h"
#include "event.h"

pid_t creat_process(process_t *p)
{
    pid_t process;
    process = fork();
    
    if (process < 0)
    {
        printf("ERROR FORK\n");
        exit(1);
    }
    if (process == 0)
    {
        printf("\nchild: %d\nname: %s\nIN: %s\nOUT: %s\n",\
        p->info.id,p->info.name,p->info.in,p->info.out);
        p->func(&(p->info));
        exit (0);
    }
    return process;
}

//===========================================================

int send(char * device, OBJECT *ptr){
    // OBJECT *ptr;&ptr;

    int fd1;
    int file1;
    char buf1;
    fd1=open(device, O_WRONLY);
    if(fd1<0){
        printf("ERROR send %d %s\n",errno,device);
        return 1;
    }
    DEBUG(("send depart: %d",ptr->event.department));
    DEBUG(("send event ptr: %0X",ptr));
    file1=write(fd1,ptr,sizeof(OBJECT));
    if(file1<0){
        printf("error on writing: %d",errno);
        return 1;
    }
    close(fd1);
    
    return 0;
}

//input = device  
OBJECT* receive(char *device){

    int fd2;
    int file2;
    OBJECT * p=malloc(sizeof(OBJECT));
    fd2=open(device,O_RDONLY);
    if(fd2<0){
        printf("ERROR on opening %s: %d\n",device, errno);
        return -1;
    }
    file2=read(fd2,p,sizeof(OBJECT));
    close(fd2);
    DEBUG(("ptr receive: %d", p->event.department));
    // DEBUG(("depart RCV : %d",p->event.addresse));
    return p;
}



//==========================================================
int send_ptr(char * device, OBJECT *ptr){
    // OBJECT *ptr;&ptr;

    int fd1;
    int file1;
    char buf1;
    fd1=open(device, O_WRONLY);
    if(fd1<0){
        printf("ERROR send %d %s\n",errno,device);
        return 1;
    }
    DEBUG(("send depart: %d",ptr->event.department));
    DEBUG(("send event ptr: %0X",ptr));
    file1=write(fd1,&ptr,sizeof(ptr));
    if(file1<0){
        printf("error on writing: %d",errno);
        return 1;
    }
    close(fd1);
    
    return 0;
}

//input = device         output=pointer de mon object
int receive_ptr(char *device,OBJECT **ptr){

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

