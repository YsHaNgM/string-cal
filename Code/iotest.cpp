#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

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

istream &operator>>(istream &is, Ops &rhs)
{
    char n;
    is >> n;
    rhs = Ops(n);
    return is;
}

void output(stack<double> &relst, double x)
{
    relst.push(x);
}

void output(stack<double> &relst, Ops s)
{
    auto num1 = relst.top();
    relst.pop();
    auto num0 = relst.top();
    relst.pop();
    switch (s)
    {
    case Ops::plus:
        relst.push(num0 + num1);
        break;
    case Ops::minus:
        relst.push(num0 - num1);
        break;
    case Ops::mul:
        relst.push(num0 * num1);
        break;
    case Ops::div:
        relst.push(num0 / num1);
        break;
    case Ops::left:
        break;
    case Ops::right:
        break;
    case Ops::eq:
        break;
    }
}

int op_preced(const Ops c)
{
    switch (c)
    {
    // case '!':
    //     return 4;
    case Ops::mul:
    case Ops::div:
        // case '%':
        return 3;
    case Ops::plus:
    case Ops::minus:
        return 2;
    case Ops::eq:
        return 1;
    case Ops::left:
        return 0;
    case Ops::right:
        break;
    } //若輸入的字元不是算子
    return 0;
}

int main()
{
    string line;
    stack<double> nums;
    stack<Ops> ops;
    while (getline(cin, line))
    {
        double x;
        Ops s;
        stringstream ss(line); //建立stringstream对象，初始化流内容为line所代表的字符串
                               // ss.exceptions(std::istream::failbit | std::istream::badbit);
                               // while (ss.good())
                               // {
                               //     try
                               //     {
        while (!ss.eof())
        {
            if (ss >> s)
            {
                if (!ops.empty())
                {
                    if (s == Ops::left)
                    {
                        ops.push(s);
                    }
                    else if (s == Ops::right)
                    {
                        while (ops.top() != Ops::left && !ops.empty())
                        {
                            output(nums, ops.top());
                            ops.pop();
                        }
                        ops.pop();
                    }
                    else
                    {
                        while (op_preced(s) <= op_preced(ops.top()))
                        {
                            output(nums, ops.top());
                            ops.pop();
                        }
                        ops.push(s);
                    }
                }
                // cout << s << endl;
            }

            else if (ss >> x)
            {
                cout << x << endl;
                nums.push(x);
            }

            while (!ops.empty())
            {
                if (ops.top() == Ops::left)
                {
                    return 1;
                }

                output(nums, ops.top());
                ops.pop();
            }
            // cout << nums.top() << endl;
            cout << "take one" << endl;
        }
        cout << nums.top() << endl;
        //     }
        //     catch (std::istream::failure &e)
        //     {
        //         /* Do your error check over here */
        //     }
        // }
        // while (ss >> x) //从line中一次读取数字存入x
        //     cout << x << endl;
    }
    return 0;
}