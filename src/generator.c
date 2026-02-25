/*
 * Module: generator.c
 *
 * Description:
 * This module is responsible for generating payload data
 * based on the selected mode.
 *
 * Supported Modes:
 *  - random : Generates alphanumeric payload
 *  - binary  : Generates random binary data using /dev/urandom
 *
 * If /dev/urandom is unavailable, it falls back to pseudo-random
 * number generation.
 *
 * This module handles core payload creation logic.
 *
 * Author: Rajan Kumar Mahato Tharu
 */

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
