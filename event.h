
#ifndef EVENT_H
#define EVENT_H
#include "process.h"
#define MAX_TXT_SIZE 30
#define MAX_ADDRESS_SIZE 20
typedef struct EVENT_TYPE {
    unsigned char department;
    char  text[MAX_TXT_SIZE];
    char  addresse[MAX_ADDRESS_SIZE];
    int severity;
    int num;
} EVENT_TYPE;

typedef struct OBJECT{
    EVENT_TYPE event;
    EVENT_TYPE * next;
} OBJECT;

// extern OBJECT * start_list;
// extern OBJECT * last;

void rand_string(char *str, size_t size);
OBJECT * new_event(void);
int creat_event_func(process_info *p);

#endif