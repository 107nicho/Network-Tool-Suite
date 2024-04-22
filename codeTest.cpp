#include <iostream>
#include <sstream>
#include <string>

int main() 
{
    std::string ipAddress;
    std::cout << "Enter an IPv4 address: ";
    std::cin >> ipAddress;

    std::stringstream ipStream(ipAddress);
    int octets[4];
    std::string octet;

    // Parse the IP address
    for (int i = 0; i < 4; i++) {
        std::getline(ipStream, octet, '.'); // Extract each octet as a string
        octets[i] = std::stoi(octet); // Convert the octet to int and store it
    }

    // Output the parsed octets
    std::cout << "The IP address " << ipAddress << " is parsed into octets as: ";
    for (int i = 0; i < 4; i++) {
        std::cout << octets[i];
        if (i < 3) std::cout << ".";
    }
    std::cout << std::endl;

    return 0;
}