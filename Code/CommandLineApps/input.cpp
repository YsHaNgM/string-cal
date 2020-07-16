#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char input)
{
    return input == '+' || input == '-' || input == '*' || input == '/' || input == '^';
}

int main()
{
    string line("2+2*3-5");
    stack<double> nums;
    stack<char> ops;
    while (!line.empty())
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (isOperator(line[i]))
            {
                string temp = line.substr(0, i);
                cout << temp << endl;
                line.erase(0, i + 1);
                break;
            }
            else if (i == (line.size() - 1))
            {
                cout << line << endl;
                line.erase(0, line.size());
                break;
            }
        }
    }

    return 0;
}