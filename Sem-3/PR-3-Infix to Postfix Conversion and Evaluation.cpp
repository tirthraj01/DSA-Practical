
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Check operator priority
int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Check whether character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char ch : infix) {
        if (ch == ' ') continue;

        if (isdigit(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (s.empty()) return "";
            s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else {
            return "";
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        if (s.top() == '(') return "";
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Evaluate postfix expression
bool evaluatePostfix(string postfix, int &result) {
    stack<int> s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else if (isOperator(ch)) {
            if (s.size() < 2) return false;

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            if (ch == '+') s.push(a + b);
            else if (ch == '-') s.push(a - b);
            else if (ch == '*') s.push(a * b);
            else {
                if (b == 0) return false;
                s.push(a / b);
            }
        }
    }

    if (s.size() != 1) return false;

    result = s.top();
    return true;
}

int main() {
    string infix;

    cout << "Enter infix expression: ";
    getline(cin, infix);

    // Convert infix to postfix
    string postfix = infixToPostfix(infix);

    if (postfix == "") {
        cout << "Invalid expression!";
        return 0;
    }

    cout << "Postfix expression: " << postfix << endl;

    // Evaluate postfix expression
    int result;

    if (evaluatePostfix(postfix, result)) {
        cout << "Evaluation: " << result << endl;
    }
    else {
        cout << "Invalid expression for evaluation!";
    }

    return 0;
}

Algorithm
Part A: Convert Infix to Postfix
1. Start.
2. Read the infix expression.
3. Create an empty stack and an empty postfix string.
4. Scan the expression from left to right.
5. If the character is a digit, add it to postfix.
6. If it is (, push it onto the stack.
7. If it is ), pop operators until ( is found.
8. If it is an operator, pop operators having higher or equal priority, then push the current operator.
9. Pop all remaining operators into postfix.
10. Display the postfix expression.
Part B: Evaluate Postfix
11. Create an empty stack.
12. Scan the postfix expression.
13. If the character is a digit, push it onto the stack.
14. If it is an operator, pop two values and perform the operation.
15. Push the result back onto the stack.
16. Display the final result.
17. Stop.
