// Header file for input output functions

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>


extern FILE *logptr;
// extern process_t proc[4];

extern void _debug (const char *fmt, ...);

// #define DEBUG(X) printf("p:%d %s:%d ",getpid(),__FILE__, __LINE__); printf X; printf("\n");
// #define DEBUG(X) fprintf(logptr,"p:%d %s:%d ",getpid(),__FILE__, __LINE__); _debug X; fprintf(logptr, "\n");
#define DEBUG(X)     logptr = fopen("debug.txt","a");fprintf(logptr,"pp:%d p:%d %s:%d ",getppid(),getpid(),__FILE__, __LINE__); _debug X;fprintf(logptr, "\n");fclose(logptr);

enum proc_index {
    DEPT1,
    DEPT2,
    DEPT3,
    DEPT4,
    DISPATCH,
    EVENT
};
#endif