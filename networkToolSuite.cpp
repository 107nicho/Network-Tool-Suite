// NETWORK TOOL SUITE
// Features binary conversion, hexadecimal conversion, subnetting, & IPv4/IPv6 formatting
// 04/18/2024

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

void v4(); // Subnet process for an ipv4 address
void v6();

int formatIP();         // Creates and stores IP address
bool decToBin(int);     // Converts dotted decimal into binary boolean string (base 10 to base 2)
int binToDec(bool[]);   // Converts a binary boolean string to  dotted decimal (base 2 to base 10)

int subnetClassA(); // Subnets a class A network
int subnetClassB(); // Subnets a class B network
int subnetClassC(); // Subnets a class C network

const int BITS = 8; // Global constant bits per octet (8)
int main()
{
    bool valid = false;
    std::string version;
    std::cout << "Enter the IP version your address uses (IPv4 or IPv6): ";
// IPv4 uses base10 to base2 and IPv6 uses hexadecimal
    while (!valid) { // Input validation loop
        std::getline(std::cin, version);
        if (version == "IPv4" || version == "ipv4" || version == "v4") { // IPv4 function call
            v4();
            valid = true;
        }
        else if (version == "IPv6" || version == "ipv6" || version == "v6") { // IPv6 function fall
            v6();
            valid = true;
        }
        else { // Input validation
            std::cout << "Invalid Internet Protocol version entered, please enter either v4 or v6: ";
        }
    }
}

void v4()
{
    int hosts;
    bool valid = false;
    while (!valid) // Input validation loop
    {
        std::cout << "Enter the number of host devices needed on the network: ";
        std::cin >> hosts;
        if (hosts <= 0) { // Input validation
            std::cout << "Invalid value entered, please enter a positive number of hosts: ";
        }
        else {
            valid = true;
        }
    }

    int IP, octet1;
    valid = false;
    while (!valid) // Input validation loop
    {
        std::cout << "Enter the network IPv4 address in dotted decimal notation: ";
        std::cin >> IP;
        if (octet1 >= 0 && octet1 <= 127) {
            subnetClassA();
            valid = true;
        }
        else if (octet1 >= 128 && octet1 <= 191) {
            subnetClassB();
            valid = true;
        }
        else if (octet1 >= 192 && octet1 <= 223) {
            subnetClassC();
            valid = true;
        }
        else if (octet1 >= 224 && octet1 <= 239) {
            std::cout << "This is a Class D network, it has no subnet mask.";
            return;
        }
        else if (octet1 >= 240 && octet1 <= 255) {
            std::cout << "This is a Class E network, it has no subnet mask.";
            return;
        }
        else { // Input validation
            std::cout << "Invalid value entered, please enter a valid IPv4 address (0.0.0.0)" << std::endl;
        }
    }
}

void v6()
{
    std::cout << "WORK IN PROGRESS.";
    return;
}

bool decToBin(int base10) // Converts dotted decimal into binary boolean string (base 10 to base 2)
{
    bool base2[BITS] = {false};
    int pow2[BITS] = {128, 64, 32, 16, 8, 4, 2, 1};
    for (int i = 0; i < BITS; i++) {
        if (base10 >= pow2[i]) {
            base2[i] = true;
            base10 -= pow2[i];
        }
        else
            base2[i] = false; 
    }
    for (int i = 0; i < BITS; i++)
        std::cout << base2[i];
}


int binToDec(bool base2[8]) //converts a binary boolean string to  dotted decimal (base 2 to base 10)
{
// Reverse engineer decToBin function once completed
    return 0;
}

int formatIP() //formats IP address into 4 octets seperated by periods
{
// Use a string and parse through the string, if code runs 
// Into a period start new number in an array of ints for each octet
    return 0;
}

int subnetClassA() {
// Implement subnetting for Class A network
    return 0;
}

int subnetClassB() {
// Implement subnetting for Class B network
    return 0;
}

int subnetClassC() {
// Implement subnetting for Class C network
    return 0;
}

/*  
IDEA
Use multidimensional array where each octet is in its own page and each bit is in its own column
int octets[4][1][8];
    const int OCTET_SIZE = 8;
    for (int i = 0; i <= OCTET_SIZE; i++) {
    }
*/