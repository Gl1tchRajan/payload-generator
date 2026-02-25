/*
 * Module: output.c
 *
 * Description:
 * This module handles output formatting and file storage.
 *
 * Responsibilities:
 *  - Print payload in hexadecimal format
 *  - Save generated payload to the output/ directory
 *  - Automatically generate timestamped filenames
 *
 * It ensures proper file organization and structured storage.
 * Author: Rajan Kumar Mahato Tharu
 */

#include <string.h>
#include "../include/payload.h"
#include <time.h>

void print_hex(const uint8_t *payload, int size)
{
    printf("\nHex Output:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%02x ", payload[i]);

        if ((i + 1) % 16 == 0)
            printf("\n");
    }

    printf("\n");
}

void save_payload(const uint8_t *payload, int size, const char *filename)
{
    char final_name[200];
    char final_path[300];   // ✅ ADD THIS HERE

    if (filename == NULL || strlen(filename) == 0)
    {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        sprintf(final_name,
                "payload_%04d%02d%02d_%02d%02d%02d.bin",
                t->tm_year + 1900,
                t->tm_mon + 1,
                t->tm_mday,
                t->tm_hour,
                t->tm_min,
                t->tm_sec);
    }
    else
    {
        strncpy(final_name, filename, sizeof(final_name) - 1);
        final_name[sizeof(final_name) - 1] = '\0';
    }

    sprintf(final_path, "output/%s", final_name);  // ✅ ADD THIS

FILE *f = fopen(final_path, "wb");
if (!f)
{
    fprintf(stderr,
        "[-] Failed to open file for writing: %s\n",
        final_path);
    return;
}
    fwrite(payload, 1, size, f);
    fclose(f);

    printf("Payload saved to: %s\n", final_path);  // ✅ Now it works
}
