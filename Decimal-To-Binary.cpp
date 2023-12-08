#include <iostream>
#include <stack>

// Function to convert decimal to binary using a stack
std::string decimalToBinary(int decimalNumber) {
    std::stack<int> binaryStack;

    // Convert decimal to binary using a stack
    while (decimalNumber > 0) {
        int remainder = decimalNumber % 2;
        binaryStack.push(remainder);
        decimalNumber /= 2;
    }

    // Pop bits from the stack to build the binary representation
    std::string binaryNumber = "";
    while (!binaryStack.empty()) {
        binaryNumber += std::to_string(binaryStack.top());
        binaryStack.pop();
    }

    return binaryNumber.empty() ? "0" : binaryNumber;
}

int main() {
    // Test the function with a decimal number
    int decimalNumber;
    
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    if (decimalNumber < 0) {
        std::cerr << "Please enter a non-negative decimal number." << std::endl;
        return 1;
    }

    std::string binaryEquivalent = decimalToBinary(decimalNumber);

    std::cout << "Decimal: " << decimalNumber << "  Binary: " << binaryEquivalent << std::endl;

    return 0;
}
