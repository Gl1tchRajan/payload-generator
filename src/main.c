/*
 * Payload Generator Project
 *
 * File: main.c
 *
 * Description:
 * This file serves as the entry point of the Payload Generator tool.
 * It handles command-line argument parsing, input validation,
 * directory creation, and orchestrates the overall workflow.
 *
 * Responsibilities:
 *  - Parse CLI arguments
 *  - Validate user input
 *  - Create required directories (output/ and logs/)
 *  - Call payload generator
 *  - Apply encryption if selected
 *  - Save output and log operations
 *
 * Author: Rajan Kumar Mahato Tharu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "../include/payload.h"
#include "../include/chacha.h"

void print_help()
{
    printf("Payload Generator Tool\n");
    printf("Usage:\n");
    printf("  ./payload -s <size> -m <mode> -o <output> -k <key>\n\n");
    printf("Options:\n");
    printf("  -s  Payload size\n");
    printf("  -m  Mode (random/binary)\n");
    printf("  -o  Output filename\n");
    printf("  -k  XOR key\n");
    printf("  -h  Help\n");
}

int main(int argc, char *argv[])
{
    int size = 0;
    char mode[20] = "random";
    char filename[200] = "payload.bin";
    char key[100] = "";

    int opt;

    while ((opt = getopt(argc, argv, "s:m:o:k:h")) != -1)
    {
        switch (opt)
        {
        case 's':
            size = atoi(optarg);
            break;

        case 'm':
            strncpy(mode, optarg, sizeof(mode) - 1);
            break;

        case 'o':
            strncpy(filename, optarg, sizeof(filename) - 1);
            break;

        case 'k':
            strncpy(key, optarg, sizeof(key) - 1);
            break;

        case 'h':
            print_help();
            return 0;

        default:
            print_help();
            return 1;
        }
    }

if (size <= 0 || size > MAX_LIMIT)
{
    fprintf(stderr,
        "[-] Invalid size! Allowed range: 1 - %d bytes\n",
        MAX_LIMIT);
    return EXIT_FAILURE;
}

if (strcmp(mode, "random") != 0 &&
    strcmp(mode, "binary") != 0)
{
    fprintf(stderr,
        "[-] Invalid mode! Use 'random' or 'binary'\n");
    return EXIT_FAILURE;
}	system("mkdir -p output");
	system("mkdir -p logs");

    uint8_t *payload = malloc(size + 1);

    if (!payload)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    generate_payload(payload, size, mode);

    if (strlen(key) > 0)
    {
        xor_encrypt(payload, size, key);
    }

    print_hex(payload, size);
    save_payload(payload, size, filename);

    write_log("Payload generated using CLI mode.");

    free(payload);

    return 0;
}
