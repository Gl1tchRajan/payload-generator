#include "../include/payload.h"
#include <time.h>
#include <string.h>

void write_log(const char *message)
{
    FILE *log = fopen("payload_log.txt", "a");

    if (!log)
        return;

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;

    fprintf(log, "[%s] %s\n", time_str, message);	
    
fclose(log);
}
