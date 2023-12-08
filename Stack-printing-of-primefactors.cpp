#include <iostream>
#include <stack>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to print prime factors in descending order using a stack
void printPrimeFactors(int n) {
    std::stack<int> primeFactors;

    // Find and push prime factors onto the stack
    for (int i = n; i >= 2; --i) {
        if (n % i == 0 && isPrime(i)) {
            primeFactors.push(i);
        }
    }

    // Print prime factors in descending order
    std::cout << "Prime factors of " << n << " in descending order: ";
    while (!primeFactors.empty()) {
        std::cout << primeFactors.top() << " ";
        primeFactors.pop();
    }
    std::cout << std::endl;
}

int main() {
    int num;

    // Input a positive integer
    std::cout << "Enter a positive integer: ";
    std::cin >> num;

    if (num <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    // Print prime factors
    printPrimeFactors(num);

    return 0;
}
