#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(1);
}

void encrypt_3des_cbc(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext) {
    DES_cblock key1, key2, key3;
    DES_key_schedule ks1, ks2, ks3;

    memcpy(key1, key, 8);
    memcpy(key2, key + 8, 8);
    memcpy(key3, key + 16, 8);

    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    DES_ede3_cbc_encrypt(plaintext, ciphertext, plaintext_len, &ks1, &ks2, &ks3, (DES_cblock *)iv, DES_ENCRYPT);
}

int main() {
    unsigned char key[24] = "0123456789abcdef01234567"; // 24-byte key for 3DES
    unsigned char iv[8] = "12345678"; // Initialization vector
    unsigned char plaintext[] = "This is a test message for 3DES CBC mode.";
    unsigned char ciphertext[128];

    int plaintext_len = strlen((char *)plaintext);

    encrypt_3des_cbc(plaintext, plaintext_len, key, iv, ciphertext);

    printf("Ciphertext is:\n");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
