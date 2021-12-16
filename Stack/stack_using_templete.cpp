#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class stack
{

    T *data;
    int top;
    int max_size;

public:
    stack()
    {
        max_size = 5;
        data = new T[max_size];
        top = -1;
    }

    void push(T new_data)
    {
        if (is_full())
        {
            T *temp;
            temp = new T[max_size * 2];
            for (int i = 0; i < max_size; i++)
            {
                temp[i] = data[i];
            }

            delete data;
            max_size *= 2;
            data = temp;
        }
        top++;
        data[top] = new_data;
    }
    bool is_full()
    {
        return top == max_size - 1;
    }

    bool is_empty()
    {
        return top <= -1;
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "Stack is Empty " << endl;
            exit(0);
        }
        top--;
    }

    void traverse()
    {
        for (int i = 0; i < max_size; i++)
        {
            cout << data[i] << endl;
        }
    }
};

int main()
{

    stack<int> s;
    s.push(3);
    s.push(32);
    s.push(33);
    s.push(39);

    s.pop();
    s.pop();

    s.push(34);
    s.push(35);
    s.push(36);
    s.push(39);

    s.pop();
    s.pop();
    s.pop();

    s.push(37);
    s.push(38);
    s.push(34);
    s.push(37);

    s.traverse();
}