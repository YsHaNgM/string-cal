#include "shuntingYard.h"

std::variant<int, char> inputParser(std::string &line)
{
    // Ex: std::string line("2+2*3-5");

    while (!line.empty())
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (isOperator(line[i]))
            {
                if (i != 0)
                {
                    std::string temp = line.substr(0, i);
                    line.erase(0, i);
                    return std::stoi(temp);
                }
                else
                {
                    auto temp = line[i];
                    line.erase(0, 1);
                    return temp;
                }
            }
            else if (i == (line.size() - 1)) // By the end of input
            {
                auto temp = line;
                line.erase(0, line.size());
                return std::stoi(temp);
            }
        }
    }
    return 0;
}

int shuntingYard(std::string line)
{
    std::stack<double> nums;
    std::stack<char> ops;
    while (!line.empty())
    {
        auto v = inputParser(line);
        if (auto pval = std::get_if<int>(&v))
        {
        }
        else if (auto pval = std::get_if<char>(&v))
        {
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
