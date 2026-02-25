#include <stdio.h>
#include "../include/chacha.h"
void chacha_encrypt(unsigned char *data, int length) {

    for(int i = 0; i < length; i++) {
        data[i] ^= 0xAA;  
    }

    printf("[+] ChaCha Encryption Applied\n");
}
