#include <iostream>
#include <stack>
#include <cctype>

class ExpressionConverter {
private:
    std::string infix;
    std::string postfix;

    // Helper function to determine the precedence of operators
    int precedence(char op) {
        if (op == '+' || op == '-') {
            return 1;
        } else if (op == '*' || op == '/') {
            return 2;
        }
        return 0; // Assuming '(' has the lowest precedence
    }

public:
    // Constructor to initialize infix and postfix strings
    ExpressionConverter() : infix(""), postfix("") {}

    // Function to set the infix expression
    void getInfix(const std::string& expression) {
        infix = expression;
    }

    // Function to display the infix expression
    void showInfix() const {
        std::cout << "Infix Expression: " << infix << std::endl;
    }

    // Function to display the postfix expression
    void showPostfix() const {
        std::cout << "Postfix Expression: " << postfix << std::endl;
    }

    // Function to convert infix expression to postfix
    void convertToPostfix() {
        std::stack<char> operators;

        // Process each symbol in the infix expression
        for (char sym : infix) {
            if (std::isalnum(sym)) {
                // Operand: append to postfix
                postfix += sym;
            } else if (sym == '(') {
                // Left parenthesis: push onto the stack
                operators.push(sym);
            } else if (sym == ')') {
                // Right parenthesis: pop and append operators until '(' is encountered
                while (!operators.empty() && operators.top() != '(') {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop(); // Discard the '('
            } else if (sym == '+' || sym == '-' || sym == '*' || sym == '/') {
                // Operator: pop and append operators with higher or equal precedence
                while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(sym)) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(sym);
            }
        }

        // Pop and append remaining operators
        while (!operators.empty()) {
            postfix += operators.top();
            operators.pop();
        }
    }
};

int main() {
    // Test the program with five expressions
    std::string expressions[] = {
        "A + B - C",
        "(A + B) * C",
        "(A + B) * (C - D)",
        "A + ((B + C) * (E - F) - G) / (H - I)",
        "A + B * (C + D) - E / F * G + H"
    };

    for (const std::string& expression : expressions) {
        ExpressionConverter converter;
        converter.getInfix(expression);
        converter.convertToPostfix();
        converter.showInfix();
        converter.showPostfix();
        std::cout << std::endl;
    }

    return 0;
}
