#include <stdio.h>
#include <ctype.h>

// Function to find modular inverse of a under modulo m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

// Function to encrypt the plaintext using affine cipher
char affineEncrypt(char p, int a, int b) {
    if (isalpha(p)) {
        p = toupper(p) - 'A';
        return (char)((a * p + b) % 26 + 'A');
    }
    return p;
}

// Function to decrypt the ciphertext using affine cipher
char affineDecrypt(char c, int a, int b) {
    if (isalpha(c)) {
        c = toupper(c) - 'A';
        int a_inv = modInverse(a, 26);
        return (char)((a_inv * (c - b + 26)) % 26 + 'A');
    }
    return c;
}

int main() {
    char plaintext[] = "HELLO";
    char ciphertext[sizeof(plaintext)];
    int a = 5; // Example value of a
    int b = 8; // Example value of b

    // Encrypt the plaintext
    for (int i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = affineEncrypt(plaintext[i], a, b);
    }
    ciphertext[sizeof(plaintext) - 1] = '\0';

    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = affineDecrypt(ciphertext[i], a, b);
    }
    plaintext[sizeof(ciphertext) - 1] = '\0';

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
