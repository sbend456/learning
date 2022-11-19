

#ifndef PROCESS_H
#define PROCESS_H 

#include "event.h"

typedef struct process_info
{   int id;
    char in[100];
    char out[100];
    char name[50];
    // pid_t pid;
} process_info;

typedef struct process_t
{
    process_info info;
    int (*func)(process_info *);
}process_t;


pid_t creat_process(process_t *p);
int receive_ptr(char *device,OBJECT **ptr);
int send_ptr(char * device, OBJECT *ptr);



#endif // PROCESS_H