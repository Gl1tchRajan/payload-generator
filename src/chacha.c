/*
 * Module: chacha.c
 *
 * Description:
 * This module contains the stream cipher implementation
 * used for encryption experimentation.
 *
 * Current Implementation:
 *  - Simplified stream-style encryption
 *  - Structural foundation for real ChaCha20 implementation
 *
 * Purpose:
 *  Demonstrates cryptographic design structure
 *  and prepares for future full ChaCha20 upgrade.
 *
 * Author: Rajan Kumar Mahato Tharu
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "chacha.h"

#define ROTL(a,b) (((a) << (b)) | ((a) >> (32 - (b))))

static void quarter_round(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d)
{
    *a += *b; *d ^= *a; *d = ROTL(*d,16);
    *c += *d; *b ^= *c; *b = ROTL(*b,12);
    *a += *b; *d ^= *a; *d = ROTL(*d,8);
    *c += *d; *b ^= *c; *b = ROTL(*b,7);
}

void chacha20_encrypt(uint8_t *data, int length,
                      const uint8_t key[32],
                      const uint8_t nonce[12])
{
    printf("[+] ChaCha20 Encryption Processing...\n");

    uint32_t state[16];
    quarter_round(&state[0], &state[4], &state[8], &state[12]);

const uint8_t constants[16] = {
    'e','x','p','a','n','d',' ','3','2','-',
    'b','y','t','e',' ','k'
};
    memcpy(&state[0], constants, 16);
    memcpy(&state[4], key, 32);
    memcpy(&state[14], nonce, 8);

    for(int i = 0; i < length; i++)
    {
        data[i] ^= key[i % 32];
    }

    printf("[+] Encryption Completed\n");
}
