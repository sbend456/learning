
#ifndef EVENT_H
#define EVENT_H

typedef struct EVENT_TYPE {
    unsigned char department;
    char  text[100];
    char  addresse[100];
    int severity;
} EVENT_TYPE;

typedef struct OBJECT{
    EVENT_TYPE event;
    EVENT_TYPE * next;
} OBJECT;

// extern OBJECT * start_list;
// extern OBJECT * last;

static char *rand_string(char *str, size_t size);
OBJECT * new_event(void);
void creat_event();
int receive(char *device,OBJECT **ptr);
int send(char * device, OBJECT *ptr);

#endif