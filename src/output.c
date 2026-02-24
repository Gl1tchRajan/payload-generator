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
    }

    FILE *f = fopen(final_name, "wb");
    if (!f)
    {
        printf("File save failed!\n");
        return;
    }

    fwrite(payload, 1, size, f);
    fclose(f);

    printf("Payload saved as: %s\n", final_name);
}
