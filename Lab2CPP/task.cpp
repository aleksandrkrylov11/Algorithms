#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

typedef Stack<int> intStack;

bool tryPush(intStack &dest, int value) {
    if (dest.empty() || value <= dest.get()) {
        dest.push(value);
        return true;
    }
    return false;
}

void tryMove(intStack &src, intStack &dest) {
    if (src.empty()) return;
    int value = src.get();
    src.pop();
    if (!tryPush(dest, value)) {
        src.push(value);
    }
}

void printStack(const intStack &s) {
    intStack copy = s;
    intStack reversed;
    while (!copy.empty()) {
        reversed.push(copy.get());
        copy.pop();
    }
    while (!reversed.empty()) {
        std::cout << static_cast<char>(reversed.get());
        reversed.pop();
    }
    std::cout << "\n";
}

int main(int argc, char **argv) {
    std::ifstream scriptFile(argv[1]);
    std::ifstream input(argv[2]);

    std::string script;
    char c;
    while (scriptFile.get(c)) script += c;

    intStack stack1, stack2, stack3;

    for (char c : script) {
        switch (c) {
            case '-': {
                if (stack2.empty()) break;
                int a = stack2.get(); stack2.pop();
                if (stack2.empty()) { stack2.push(a); break; }
                int b = stack2.get(); stack2.pop();
                stack2.push(b);
                stack2.push(b - a);
                break;
            }
            case '>': {
                if (stack2.empty()) break;
                int v = stack2.get(); stack2.pop();
                stack2.push(v);
                stack2.push(v);
                break;
            }
            case '<': {
                if (stack2.empty()) break;
                int a = stack2.get(); stack2.pop();
                if (stack2.empty()) { stack2.push(a); break; }
                int b = stack2.get(); stack2.pop();
                if (a == b) {
                    stack2.push(a);
                } else {
                    std::cerr << "Error\n";
                    return 1;
                }
                break;
            }
            case '(': tryMove(stack1, stack2); break;
            case ')': tryMove(stack2, stack1); break;
            case '[': tryMove(stack3, stack2); break;
            case ']': tryMove(stack2, stack3); break;
            case '{': {
                char ch;
                if (input.get(ch)) {
                    tryPush(stack2, static_cast<unsigned char>(ch));
                }
                break;
            }
            case '}': {
                if (stack2.empty()) break;
                int v = stack2.get(); stack2.pop();
                std::cout << static_cast<char>(v);
                break;
            }
            default:
                break;
        }
    }

    printStack(stack1);
    printStack(stack2);
    printStack(stack3);

    return 0;
}