#include <iostream>
#include <string>
using namespace std;

struct balanced_parenthesis
{
    char *stack;
    int top;
};

typedef struct balanced_parenthesis bp;
void initialize(bp *b)
{
    b->stack = new char[10];
    b->top = -1;
}
void push(bp *b, char c)
{
    b->stack[++b->top] = c;
}
int check(char c)
{
    if (c == '[' || c == ']')
    {
        return 3;
    }
    else if (c == '{' || c == '}')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

bool pop(bp *b, char c)
{
    return (check(c) == check(b->stack[b->top--]));
}

bool check_parenthesis(bp *b, string exp)
{
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(b, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            return (pop(b, exp[i]));
        }
    }

    return (b->top == -1);
}

int main()
{

    bp b;

    initialize(&b);

    string exp;
    cout << "Enter a expression: " << endl;

    cin >> exp;

    if (check_parenthesis(&b, exp))
    {
        cout << "expresion is balanced parenthesis " << endl;
    }
    else
    {
        cout << "expresion is not balanced parenthesis " << endl;
    }
}