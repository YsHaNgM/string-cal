#include <iostream>
#include <string>

using namespace std;
// namespace std;

class Program
{
private:
    string expression;
    int indexOfPreviousOperator;
    int indexOfNextOperator;

public:
    Program(string ex)
    {
        expression = ex;
    }

    void Evaluate()
    {
        int result = 0;

        if ((expression.find('+') == string::npos && expression.find('-') == string::npos && expression.find('*') == string::npos && expression.find('/') == string::npos))
        {
            cout << stoi(expression);
        }

        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == '/')
            {
                result = getFirstOperand(i) / getSecondOperand(i);
                expression.erase(indexOfPreviousOperator, indexOfNextOperator - indexOfPreviousOperator);
                expression.insert(indexOfPreviousOperator, to_string(result));
                Evaluate();
            }
            else if (expression[i] == '*')
            {
                result = getFirstOperand(i) * getSecondOperand(i);
                expression.erase(indexOfPreviousOperator, indexOfNextOperator - indexOfPreviousOperator);
                expression.insert(indexOfPreviousOperator, to_string(result));
                Evaluate();
            }
            else if (expression[i] == '+' && expression.find('/') == string::npos && expression.find('*') == string::npos)
            {
                result = getFirstOperand(i) + getSecondOperand(i);
                expression.erase(indexOfPreviousOperator, (indexOfNextOperator - indexOfPreviousOperator));
                expression.insert(indexOfPreviousOperator, to_string(result));
                Evaluate();
            }
            else if (expression[i] == '-' && expression.find('/') == string::npos && expression.find('*') == string::npos)
            {
                result = getFirstOperand(i) - getSecondOperand(i);
                expression.erase(indexOfPreviousOperator, indexOfNextOperator - indexOfPreviousOperator);
                expression.insert(indexOfPreviousOperator, to_string(result));
                Evaluate();
            }
        }
    }

    int getFirstOperand(int index)
    {
        string operand = "";
        indexOfPreviousOperator = 0;

        for (int i = (index - 1); i >= 0; i--)
        {
            if (!isdigit(expression[i]))
            {
                indexOfPreviousOperator = i;
                break;
            }
        }
        operand = expression.substr(indexOfPreviousOperator, (index - indexOfPreviousOperator));
        return stoi(operand);
    }

    int getSecondOperand(int index)
    {
        string operand = "";
        indexOfNextOperator = expression.size();

        for (int i = (index + 1); i < expression.size(); i++)
        {
            if (!isdigit(expression[i]))
            {
                indexOfNextOperator = i;
                break;
            }
        }
        operand = expression.substr((index + 1), (indexOfNextOperator - index - 1));
        return stoi(operand);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
