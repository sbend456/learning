#ifndef PROCESS_H
#define PROCESS_H
typedef struct process_info
{   int id;
    char in[100];
    char out[100];
    char name[50];
} process_info;

typedef struct process_t
{
    process_info info;
    int (*func)(process_info *);
}process_t;

void creat_process(process_t *p);


#endif // PROCESS_H