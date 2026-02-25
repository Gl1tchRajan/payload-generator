#ifndef CHACHA_H
#define CHACHA_H

#include <stdint.h>

void chacha20_encrypt(
    uint8_t *data,
    int length,
    const uint8_t key[32],
    const uint8_t nonce[12]
);

#endif
