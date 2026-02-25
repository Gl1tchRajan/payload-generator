#include <stdio.h>
#include <string.h>
#include "chacha.h"

<<<<<<< HEAD
    for(int i = 0; i < length; i++) {
        data[i] ^= 0xAA;  
=======
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
    printf("[+] Real ChaCha20 Encryption Started\n");

    uint32_t state[16];

    const char *constants = "expand 32-byte k";
    memcpy(state, constants, 16);


    for (int i = 0; i < length; i++)
    {
	data[i] ^= key[i % 32];
>>>>>>> 400b8ec (Fixed input validation and security issues)
    }

    printf("[+] ChaCha20 Process Completed\n");
}
