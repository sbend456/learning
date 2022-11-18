
typedef struct process_t
{
    int id;
    char in[100];
    char out[100];
    char name[50];
    int (*func)(int);
} process_t;

void creat_process(process_t *p);