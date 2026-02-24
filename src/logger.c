#include "../include/payload.h"
#include <time.h>

void write_log(const char *message)
{
    FILE *log = fopen("payload_log.txt", "a");

    if (!log)
        return;

    time_t now = time(NULL);
    fprintf(log, "[%s] %s\n", ctime(&now), message);

    fclose(log);
}
