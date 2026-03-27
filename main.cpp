#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
};

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

bool isNumber(const string& s) {
    if (s.empty()) {
        return false;
    }

    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int precedence(const string& op) {
    // TODO
    if (op == "+" || op == "-") {
        return 1;
    }

    if (op == "*" || op == "/") {
        return 2;
    }
    return 0;
}

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    // TODO
    for (size_t i = 0; i < line.length(); i++) {
        char c = line[i];

        if (isspace(c)) {
            continue;
        }

        if (isdigit(c)) {
            string number;
            size_t temp = i;

            while (temp < line.length() && isdigit(line[temp])) { //handles multiple digits
                number += line[temp];
                temp++;
            }

            tokens.push_back({number});
            i = temp - 1;
        }
        else {
            string s;
            s += c;
            if (isOperator(s)) {
                tokens.push_back({s});
            }
            else if (s == "(" || s == ")") {
                tokens.push_back({s});
            }
        }
    }
    return tokens;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    // TODO
    int ctr = 0;
    for (int i = 0; i < tokens.size(); i++) {

        if (tokens[i].value == "(" || tokens[i].value == ")") {
            return false;
        }

        if (isNumber(tokens[i].value)) {
            ctr++;
        }

        else if (isOperator(tokens[i].value)) {
            if (ctr < 2) {
                return false;
            }
            ctr--;
        }
        else {
            return false;
        }
    }
    return ctr == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    // TODO
    bool expectOp = false;
    ArrayStack<Token> s;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].value == "(") {
            if (expectOp) {
                return false;
            }
            s.push(tokens[i]);
        }
        else if (tokens[i].value == ")") {
            if (s.empty() || !expectOp) {
                return false;
            }
            s.pop();
        }
        else if (isNumber(tokens[i].value) ) {
            expectOp = true;
        }
        else if (isOperator(tokens[i].value) && expectOp) {
            expectOp = false;
        }
        else {
            return false;
        }
    }

    if (!s.empty() || !expectOp) {
        return false;
    }

    return true;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    //ArrayStack<double> stack;
    // TODO
    return 0.0;
}

// Main

int main() {
    string line = "(1 + 2) * 3"; //test
    //getline(cin, line);

    vector<Token> tokens = tokenize(line);

    cout << isValidPostfix(tokens) << endl;
    cout << isValidInfix(tokens) << endl;

    // if (isValidPostfix(tokens)) {
    //     cout << "FORMAT: POSTFIX\n";
    //     cout << "RESULT: " << evalPostfix(tokens) << "\n";
    // }
    // else if (isValidInfix(tokens)) {
    //     vector<Token> postfix = infixToPostfix(tokens);
    //     cout << "FORMAT: INFIX\n";
    //     cout << "POSTFIX: ";
    //     for (const auto& t : postfix) {
    //         cout << t.value << " ";
    //     }
    //     cout << "\n";
    //     cout << "RESULT: " << evalPostfix(postfix) << "\n";
    // }
    // else {
    //     cout << "FORMAT: NEITHER\n";
    //     cout << "ERROR: invalid expression\n";
    // }

    return 0;
}
