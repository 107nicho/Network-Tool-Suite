// NETWORK TOOL SUITE
// Features binary conversion, hexadecimal conversion, subnetting, & IPv4/IPv6 formatting
// 04/18/2024

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

enum class ipVersion {
    IPv4,
    IPv6,
    Invalid
};

ipVersion getIPv(const std::string&);    // Detect IP version
void v4();      // Subnet IPv4 address
void v6();      // IPv6
int subnetClassA();     // Subnets a class A network
int subnetClassB();     // Subnets a class B network
int subnetClassC();     // Subnets a class C network
bool decToBin(int);     // Converts dotted decimal into binary boolean string (base 10 to base 2)
int binToDec(bool[]);   // Converts a binary boolean string to  dotted decimal (base 2 to base 10)

const int BITS = 8; // Global constant bits per octet (8)
int main() {
    std::string ipAddress;
    ipVersion version = ipVersion::Invalid;

    while (version == ipVersion::Invalid) {
        std::cout << "Enter an IP address: ";
        std:: cin >> ipAddress;

        ipVersion version = getIPv(ipAddress);

        switch (version) {
            case ipVersion::IPv4:
                std::cout << "The entered IP address is IPv4";
                v4();
                break;
            case ipVersion::IPv6:
                std::cout << "The entered IP address is IPv6";
                v6();
                break;
            case ipVersion::Invalid:
                std::cout << "Invalid IP version";
                break;

        }
    }
}

ipVersion getIPv(const std::string& ipAddress) {
    if (ipAddress.find('.') != std::string::npos) {
        return ipVersion::IPv4;
    }
    else if (ipAddress.find(':') != std::string::npos) {
        return ipVersion::IPv6;
    }
}

void v4() {
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

    std::string ipAddress;
    int octets[4];
    valid = false;
    while (!valid) // Input validation loop
    {
        std::cout << "Enter the network IPv4 address in dotted decimal notation: ";
        std::cin >> ipAddress;

        std::stringstream ipStream(ipAddress);
        std::string octet;

        for (int i = 0; i < 4; i++) {
            std::getline(ipStream, octet, '.'); // Parses through the string and separates each octet as a string
            octets[i] = std::stoi(octet); // Converts string octet to int
        }
        
        if (octets[0] >= 0 && octets[0] <= 127) {
            subnetClassA();
            valid = true;
        }
        else if (octets[0] >= 128 && octets[0] <= 191) {
            subnetClassB();
            valid = true;
        }
        else if (octets[0] >= 192 && octets[0] <= 223) {
            subnetClassC();
            valid = true;
        }
        else if (octets[0] >= 224 && octets[0] <= 239) {  // Multicast
            std::cout << "This is a Class D network, it has no subnet mask.";
            return;
        }
        else if (octet[0] >= 240 && octets[0] <= 255) {  // Experimental
            std::cout << "This is a Class E network, it has no subnet mask.";
            return;
        }
        else { // Input validation
            std::cout << "Invalid value entered, please enter a valid IPv4 address (0.0.0.0)" << std::endl;
        }
    }
}

void v6() {
    std::cout << "WORK IN PROGRESS.";
    return;
}

bool decToBin(int base10) { // Converts dotted decimal into binary boolean string
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


int binToDec(bool base2[8]) { // Converts a binary boolean string to dotted decimal notation
// Reverse engineer decToBin function once completed
    return 0;
}

int subnetClassA() { // Implement subnetting for Class A network
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