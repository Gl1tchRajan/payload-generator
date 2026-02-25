#ifndef PAYLOAD_H
#define PAYLOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LIMIT 1024

void generate_payload(uint8_t *payload, int size, const char *mode);

void xor_encrypt(uint8_t *payload, int size, const char *key);

void print_hex(const uint8_t *payload, int size);
void print_base64(const uint8_t *payload, int size);
void save_payload(const uint8_t *payload, int size, const char *filename);

void write_log(const char *message);

#endif
