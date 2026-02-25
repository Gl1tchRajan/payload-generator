#include "../include/payload.h"
#include <string.h>
#include "../include/chacha.h"
int main()
{
    int size;
    char mode[20] = "random";
    char key[100] = "";
    char filename[200] = "";
    char choice;

    printf("Enter Payload Size (Max %d): ", MAX_LIMIT);

    if (scanf("%d", &size) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (size <= 0 || size > MAX_LIMIT)
    {
        printf("Invalid payload size!\n");
        return 1;
    }

    uint8_t *payload = malloc(size + 1);

    if (!payload)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Mode (random/binary): ");
    scanf("%19s", mode);

    generate_payload(payload, size, mode);

    printf("Encrypt with XOR? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter XOR Key: ");
        scanf("%99s", key);
        xor_encrypt(payload, size, key);
    }

char chacha_choice;
printf("Encrypt with ChaCha20? (y/n): ");
scanf(" %c", &chacha_choice);

if (chacha_choice == 'y' || chacha_choice == 'Y')
{
uint8_t key[32] = {0};
uint8_t nonce[12] = {0};

printf("Enter 32-byte key (hex or string simplified): ");
scanf("%32s", key);

printf("Enter 12-byte nonce: ");
scanf("%12s", nonce);

chacha20_encrypt(payload, size, key, nonce);
}

    print_hex(payload, size);

    printf("Enter filename to save (optional): ");
    scanf("%199s", filename);

    save_payload(payload, size, filename);

    write_log("Program executed successfully.");

    free(payload);
    return 0;
}
