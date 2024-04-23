// NETWORK TOOL SUITE
// Features binary conversion, hexadecimal conversion, subnetting, & IPv4/IPv6 support
// 04/18/2024

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>

enum class IPVersion {  // Stores version cases
    IPv4,
    IPv6,
    Invalid
};

IPVersion getIPVersion(const std::string&); // Detect IP version
void processIPv4();     // Subnet IPv4 address
void processIPv6();     // IPv6
int subnetClassA();     // Subnets a class A network
int subnetClassB();     // Subnets a class B network
int subnetClassC();     // Subnets a class C network
void decimalToBinary(int);     // Converts dotted decimal into binary boolean string (base 10 to base 2)
int binaryToDecimal(bool[]);   // Converts a binary boolean string to  dotted decimal (base 2 to base 10)

int main() {
    std::string ipAddress;
    IPVersion version = IPVersion::Invalid;

    while (version == IPVersion::Invalid) {
        std::cout << "Enter an IP address: ";
        std::cin >> ipAddress;

        version = getIPVersion(ipAddress);

        switch (version) {
            case IPVersion::IPv4:
                std::cout << "The entered IP address is IPv4." << std::endl;
                processIPv4();
                break;
            case IPVersion::IPv6:
                std::cout << "The entered IP address is IPv6." << std::endl;
                processIPv6();
                break;
            case IPVersion::Invalid:
                std::cout << "Invalid IP version." << std::endl;
                break;
        }
    }
}

IPVersion getIPVersion(const std::string& ipAddress) {
    if (ipAddress.find('.') != std::string::npos) {
        return IPVersion::IPv4;
    }
    else if (ipAddress.find(':') != std::string::npos) {
        return IPVersion::IPv6;
    }
    else
        return IPVersion::Invalid;
}

void processIPv4() {
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
    std::string octet;

    valid = false;
    while (!valid) // Input validation loop
    {
        std::cout << "Enter the network IPv4 address in dotted decimal notation: ";
        std::cin >> ipAddress;

        std::stringstream ipStream(ipAddress);

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