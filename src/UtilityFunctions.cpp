// Utilities
// Includes binary and hexadecimal conversion

#include <iostream>

void decimalToBinary();
int binaryToDecimal();

int main() {
    
}

void decimalToBinary(int base10) { // Converts dotted decimal into binary boolean string
    const int BITS_PER_OCTET = 8; 
    bool base2[BITS_PER_OCTET] = {false};
    int pow2[BITS_PER_OCTET] = {128, 64, 32, 16, 8, 4, 2, 1};
    for (int i = 0; i < BITS_PER_OCTET; i++) {
        if (base10 >= pow2[i]) {
            base2[i] = true;
            base10 -= pow2[i];
        }
        else
            base2[i] = false; 
    }
    for (int i = 0; i < BITS_PER_OCTET; i++)
        std::cout << base2[i];
}

int binaryToDecimal(bool base2[8]) { // Converts a binary boolean string to dotted decimal notation
// Reverse engineer decToBin function once completed
    return 0;
}