/*

Algorithms:
1. append "(" and ")" to the expression.
2. if "(" is present push it in postfix.
3. if alphabet is present push it postfix.
4. if ")" is present, keep popping from stack and push to postfix
    till "(" is found.
5.if operator is present,
    if its precedence is lower or equal than operator of top of stack
        keep popping from stack and push to postfix
    else
        push it to the stack
*/

#include <iostream>
#include <string>
using namespace std;

int top = -1;
string postfix = "";

void push(char *stack, char c)
{
    top++;
    stack[top] = c;
}
bool contains_optr(char c)
{

    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}
void pop_bracket(char *stack)
{
    for (int i = top; i > 0; i--)
    {
        if (stack[i] == '(')
        {
            top--;
            return;
        }
        postfix += stack[i];
        top--;
    }
}
int precedence(char a)
{
    if (a == '$')
    {
        return 3;
    }

    else if (a == '/' || a == '*')
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
void pop_optr(char *stack, char a)
{
    int i = top;

    while (contains_optr(stack[i]) && precedence(a) <= precedence(stack[top]))
    {
        postfix += stack[top];
        top--;
        i--;
    }
    push(stack, a);
    return;
}

string convert(string infix, char *stack)
{
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            push(stack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            pop_bracket(stack);
        }
        else if (contains_optr(infix[i]))
        {
            if (contains_optr(stack[top]))
            {

                (precedence(infix[i]) <= precedence(stack[top])) ? pop_optr(stack, infix[i]) : push(stack, infix[i]);
            }
            else
            {
                push(stack, infix[i]);
            }
        }
        else
        {
            postfix += infix[i];
        }
    }
    return postfix;
}

int main()
{
    string infix;
    char stack[20];
    cout << "Enter a infix expresion: " << endl;
    cin >> infix;

    infix = "(" + infix + ")";

    postfix = convert(infix, stack);
    cout << "The required postfix is: " << endl;
    cout << postfix << endl;
}