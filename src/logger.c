/*
 * Module: logger.c
 *
 * Description:
 * This module manages logging functionality.
 *
 * Responsibilities:
 *  - Record tool execution events
 *  - Store logs inside the logs/ directory
 *  - Track payload generation activities
 *
 * Purpose:
 *  Improves traceability and debugging capability
 *  for tool execution.
 *
 * Author: Rajan Kumar Mahato Tharu
 */

#include "../include/payload.h"
#include <time.h>
#include <string.h>

void write_log(const char *message)
{
FILE *log = fopen("logs/payload_log.txt", "a");
if (!log)
{
    fprintf(stderr,
        "[-] Logging failed! Cannot open log file.\n");
    return;
}
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strcspn(time_str, "\n")] = 0;

    fprintf(log, "[%s] %s\n", time_str, message);	
    
fclose(log);
}
