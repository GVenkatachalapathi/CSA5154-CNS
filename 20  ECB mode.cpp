#include <stdio.h>
#include <string.h>


void print_data(const char *title, const void* data, int len) {
    printf("%s : ", title);
    const unsigned char *p = (const unsigned char*)data;
    for (int i = 0; i < len; ++i)
        printf("%02X ", *p++);
    printf("\n");
}

int main() {
    // Key and plaintext
    unsigned char key[AES_BLOCK_SIZE] = "0123456789abcdef";
    unsigned char plaintext[AES_BLOCK_SIZE] = "HelloWorld123456";
    unsigned char ciphertext[AES_BLOCK_SIZE];
    unsigned char decryptedtext[AES_BLOCK_SIZE];

    // Initialize AES key structure
    AES_KEY enc_key, dec_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_set_decrypt_key(key, 128, &dec_key);

    // Encrypt plaintext
    AES_encrypt(plaintext, ciphertext, &enc_key);
    print_data("Ciphertext", ciphertext, AES_BLOCK_SIZE);

    // Decrypt ciphertext
    AES_decrypt(ciphertext, decryptedtext, &dec_key);
    print_data("Decrypted text", decryptedtext, AES_BLOCK_SIZE);

    return 0;
}
