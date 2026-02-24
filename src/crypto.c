#include "../include/payload.h"
#include <string.h>

void xor_encrypt(uint8_t *payload, int size, const char *key)
{
    int key_len = strlen(key);

    if (key_len == 0)
        return;

    for (int i = 0; i < size; i++)
        payload[i] ^= (uint8_t)key[i % key_len];

    write_log("Payload encrypted with XOR.");
}
