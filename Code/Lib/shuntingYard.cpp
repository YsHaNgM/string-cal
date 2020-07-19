#include "shuntingYard.h"

#include <iostream>

std::variant<int, char> inputParser(std::string &line)
{
    std::string line("2+2*3-5");
    std::stack<double> nums;
    std::stack<char> ops;
    while (!line.empty())
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (isOperator(line[i]) && i != 0)
            {
                std::string temp = line.substr(0, i);
                line.erase(0, i);
                return std::stoi(temp);
            }
            else if (i == (line.size() - 1))
            {
                auto temp = line;
                line.erase(0, line.size());
                return std::stoi(temp);
            }
        }
    }
}
