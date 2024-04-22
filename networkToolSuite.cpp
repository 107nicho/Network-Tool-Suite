// SUBNETTING CALCULATOR
// Includes: Binary conversion, hexadecimal conversion, subnetting, IPv4 and IPv6 formatting
// 04/18/2024

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>

void v4(); //subnet process for an ipv4 address
void v6();

int formatIP(); //creates and stores IP address
bool decToBin(int); //converts dotted decimal into binary boolean string (base 10 to base 2)
int binToDec(bool[]); //converts a binary boolean string to  dotted decimal (base 2 to base 10)

int subnetClassA(); //subnets a class A network
int subnetClassB(); //subnets a class B network
int subnetClassC(); //subnets a class C network

const int BYTE = 8; //global constant for size of each octet/the amount of bits per byte (8)
int main()
{
    bool valid;
    std::string version;
    std::cout << "Enter the IP version for your address (IPv4 or IPv6): ";
//ipv4 uses base10 to base2 and ipv6 uses hexadecimal
    while (valid = false) { //input validation loop
        std::getline(std::cin, version);
        if (version == "IPv4" || version == "ipv4" || version == "v4") { //IPv4 function call
            v4();
            !valid;
        }
        else if (version == "IPv6" || version == "ipv6" || version == "v6") { //IPv6 function fall
            v6();
            !valid;
        }
        else { //input validation
            std::cout << "Invalid Internet Protocol version entered, please enter either v4 or v6: ";
        }
    }
}

void v4()
{
    int IP, hosts, octet1;
    bool valid;

    while (valid = false) //input validation loop
    {
        std::cout << "Enter the number of host devices needed on the network:  ";
        std::cin >> hosts;
        if (hosts <= 0) { //input validation
            std::cout << "Invalid value entered, please enter a positive number of hosts: ";
            std::cin >> hosts;
        }

        std::cout << "Enter the network IPv4 address (0.0.0.0): ";
        std::cin >> IP;
        if (octet1 >= 0 && octet1 <= 127) {
            subnetClassA();
            !valid;
        }
        else if (octet1 >= 128 && octet1 <= 191) {
            subnetClassB();
            !valid;
        }
        else if (octet1 >= 192 && octet1 <= 223) {
            subnetClassC();
            !valid;
        }
        else if (octet1 >= 224 && octet1 <= 239) {
            std::cout << "This is a Class D network, it has no subnet mask.";
            exit;
        }
        else if (octet1 >= 240 && octet1 <= 255) {
            std::cout << "This is a Class E network, it has no subnet mask.";
            exit;
        }
        else { //input validation
            std::cout << "Invalid value entered, please enter a valid IPv4 address (0.0.0.0)" << std::endl;
        }
    }
}

void v6()
{
    std::cout << "WORK IN PROGRESS.";
    exit;
}

bool decToBin(int base10) //converts dotted decimal into binary boolean string (base 10 to base 2)
{
    std:: cout << "Please enter a decimal number to convert: ";
    std:: cin >> base10;
    bool base2[BYTE] = {false};
    int pow2[BYTE] = {128, 64, 32, 16, 8, 4, 2, 1};
    for (int i = 0; i < BYTE; i++) {
        if (base10 >= pow2[i]) {
            base2[i] = true;
            base10 -= pow2[i];
        }
        else
            base2[i] = false; 
    }
    for (int i = 0; i < BYTE; i++)
        std::cout << base2[i];
}


int binToDec(bool base2[8]) //converts a binary boolean string to  dotted decimal (base 2 to base 10)
{
        
}

int formatIP() //formats IP address into 4 octets seperated by periods
{
// use a string and parse through the string, if code runs 
// into a period start new number in an array of ints for each octet
}


/*  
    idea
    int octets[4][1][8];
        const int OCTET_SIZE = 8;
        for (int i = 0; i <= OCTET_SIZE; i++) {
        }

use an array of bools for 1s and 0s
use multidimensional array where each octet is in its own page and each bit is in its own column
*/