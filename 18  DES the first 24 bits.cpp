#include <stdio.h>
#include <stdint.h>

// Function to generate subkeys
void generate_subkeys(uint64_t initial_key, uint32_t subkeys[16][2]) {
    uint32_t C = (initial_key >> 28) & 0xFFFFFFF; // First 28 bits
    uint32_t D = initial_key & 0xFFFFFFF;        // Last 28 bits

    for (int i = 0; i < 16; i++) {
        // Perform left shifts (example shift schedule)
        C = ((C << 1) | (C >> 27)) & 0xFFFFFFF;
        D = ((D << 1) | (D >> 27)) & 0xFFFFFFF;

        // Combine C and D to form the subkey
        subkeys[i][0] = (C >> 4) & 0xFFFFFF; // First 24 bits from C
        subkeys[i][1] = (D >> 4) & 0xFFFFFF; // First 24 bits from D
    }
}

int main() {
    uint64_t initial_key = 0x133457799BBCDFF1; // Example 64-bit key
    uint32_t subkeys[16][2];

    generate_subkeys(initial_key, subkeys);

    // Print the subkeys
    for (int i = 0; i < 16; i++) {
        printf("Subkey %d: %06X %06X\n", i + 1, subkeys[i][0], subkeys[i][1]);
    }

    return 0;
}
