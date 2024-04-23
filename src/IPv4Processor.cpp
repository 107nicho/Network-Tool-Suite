// IPv4 Processor

#include <iostream>
#include <string>
#include <sstream>

int subnetClassA();
int subnetClassB();
int subnetClassC();

int main() {
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