#include "../include/payload.h"
#include <string.h>
#include <time.h>

void generate_payload(uint8_t *payload, int size, const char *mode)
{
    const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";

    srand(time(NULL));

    if (strcmp(mode, "binary") == 0)
    {
        FILE *f = fopen("/dev/urandom", "rb");
        if (f)
        {
            fread(payload, 1, size, f);
            fclose(f);
        }
        else
        {
            for (int i = 0; i < size; i++)
                payload[i] = rand() % 256;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
            payload[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    payload[size] = '\0';
}
