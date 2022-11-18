#include "main.h"
#include "increment.h"

int incremente(int num){
    int count = 0;
    char path[100];
    sprintf(path,"./f%d.txt",num);
    FILE *file=fopen(path,"wa");
    while (count!=10)
    {
        // fprintf(file,"count : %d\n", count);
        DEBUG (("count : %d\n",count));
        fclose(file);
        fopen(path,"a");
        count++;
        sleep(num);
    }
    fclose(file);
    return 0;
}