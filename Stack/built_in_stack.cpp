#include <iostream>
#include <stack>
// using namespace std;

int main()
{
    std::stack<int> s1;

    // push items in the stcaks
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    // access the top element of the stack
    std::cout << s1.top() << std::endl;

    // delete top element
    s1.pop();

    std::cout << s1.top() << std::endl;

    //  size of the stack
    std::cout << s1.size() << std::endl;

    // checks wether empty or not
    std::cout << s1.empty() << std::endl;
}