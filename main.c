// #ifndef MAIN_C
// #define MAIN_C

#include "main.h"
#include "department.h"
#include "process.h"
#include "event.h"
#include "dispatcher.h"

FILE *logptr;
int init_device_nr;
int step_device;

// enum proc_index ind;
void _debug(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vfprintf(logptr, fmt, args);
    va_end(args);
}

// main function
int main(int argc, char **argv)
{
    int i;
    int count;
    logptr = fopen("debug.txt", "w");
    fclose(logptr);
    DEBUG(("App Started Arg count:%d", argc));
    for (i = 0; i < argc; i++)
    {
        DEBUG(("Arg %d: %s", i, argv[i]));
    }
    printf("Open a terminal and Create 6 socat pipes \n");
    printf("by executing on terminal the command below 6 times\n");
    printf("socat -d -d PTY,raw PTY,raw &\n");
    printf("Once executed Enter in the app the number of the first created device\n");
    scanf("%d", &init_device_nr);
    printf("give value between two created devices (ie: 2)\n");
    scanf("%d", &step_device);

    // Start of Implementation
    {
        // create table of pids for 6 processes that will be created so that we can kill them on exit
        pid_t pid[6];
        process_t proc[6];

        // create 4 department processes and assign them their socat pipe b};
        int cur_device_nr=init_device_nr;
        for (int i = DEPT1; i < DEPT4+1; i++)
        {
            proc[i].info.id = i + 1;
            sprintf(proc[i].info.name, "Department_Process%d", i + 1);
            sprintf(proc[i].info.in, "/dev/pts/%d", cur_device_nr);
            sprintf(proc[i].info.out, "/dev/pts/%d", cur_device_nr + 1);
            cur_device_nr = cur_device_nr + step_device;
            proc[i].func = department;
            pid[i] = creat_process(&proc[i]);
            DEBUG(("PID_VALUE FOR INDEX %d, %d", i, pid[i]));
        }
        // i points now to DISPATCH
        proc[i].info.id = i + 1;
        sprintf(proc[i].info.name, "Department_Process%d", i + 1);
        sprintf(proc[i].info.in, "/dev/pts/%d", cur_device_nr);
        sprintf(proc[i].info.out, "/dev/pts/%d", cur_device_nr + 1);
        cur_device_nr = cur_device_nr + step_device;
        proc[i].func = dispacher_fuc;
        pid[i] = creat_process(&proc[i]);
        i++; // i points now to CREATE_EVENT
        proc[i].info.id = i + 1;
        sprintf(proc[i].info.name, "Department_Process%d", i + 1);
        sprintf(proc[i].info.in, "/dev/pts/%d", cur_device_nr);
        sprintf(proc[i].info.out, "/dev/pts/%d", cur_device_nr + 1);
        cur_device_nr = cur_device_nr + step_device;
        proc[i].func = creat_event_func;
        pid[i] = creat_process(&proc[i]);

        char ch;
        while ((ch = getchar()) != 'q')
        {
            sleep(1);
        }
        for (int i = 0; i < 6; i++)
        {
            DEBUG(("KIILLING SUBROCESS %i %d", i, pid[i]));
            kill(pid[i], SIGKILL);
        }
    }
    // closing app
    DEBUG(("App exit"));
    // fclose(logptr);
    return 0;
}

// #endif