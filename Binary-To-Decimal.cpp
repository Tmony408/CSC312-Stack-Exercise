#include <iostream>
#include <stack>

// Function to convert binary to decimal using a stack
int binaryToDecimal(const std::string& binaryNumber) {
    std::stack<int> binaryStack;

    // Push each bit onto the stack
    for (char bit : binaryNumber) {
        if (bit == '0' || bit == '1') {
            binaryStack.push(bit - '0'); // Convert char to int (0 or 1) and push onto the stack
        } else {
            std::cerr << "Invalid binary digit: " << bit << std::endl;
            return -1; // Return an error code for invalid input
        }
    }

    // Process the bits to calculate the decimal equivalent
    int decimalNumber = 0;
    int weight = 0;

    while (!binaryStack.empty()) {
        int bit = binaryStack.top();
        binaryStack.pop();
        decimalNumber += bit * (1 << weight); // Equivalent to bit * pow(2, weight)
        weight++;
    }

    return decimalNumber;
}

int main() {
    // Test the function with provided binary numbers
    std::string binaryNumbers[] = {"11000101", "10101010", "11111111", "10000000", "1111100000"};

    for (const std::string& binaryNumber : binaryNumbers) {
        int decimalEquivalent = binaryToDecimal(binaryNumber);
        
        if (decimalEquivalent != -1) {
            std::cout << "Binary: " << binaryNumber << "  Decimal: " << decimalEquivalent << std::endl;
        } else {
            std::cerr << "Error converting binary to decimal for input: " << binaryNumber << std::endl;
        }
    }

    return 0;
}
