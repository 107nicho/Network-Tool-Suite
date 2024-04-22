#include <iostream>

int main() 
{
    int dec;
    std:: cout << "Please enter a decimal number to convert: ";
    std:: cin >> dec;
    const int BIN_SIZE = 8;
    bool bin[BIN_SIZE] = {false};
    int fac2[BIN_SIZE] = {128, 64, 32, 16, 8, 4, 2, 1};
    for (int i = 0; i < BIN_SIZE; i++) {
        if (dec >= fac2[i]) {
            bin[i] = true;
            dec -= fac2[i];
        }
        else
            bin[i] = false;
    }
    for (int i = 0; i < BIN_SIZE; i++) {
        std::cout << bin[i];
    }
}