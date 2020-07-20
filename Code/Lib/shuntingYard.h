#ifndef shuntingYard_h
#define shuntingYard_h

#include <coroutine>
#include <stack>
#include <string>
#include <variant>

enum class Ops : char
{
    plus = '+',
    minus = '-',
    mul = '*',
    div = '/',
    left = '(',
    right = ')',
    eq = '='
};

bool isOperator(char input)
{
    return input == '+' || input == '-' || input == '*' || input == '/' || input == '^';
}

std::variant<int, char> inputParser(std::string &);

int shuntingYard(std::string &);

#endif