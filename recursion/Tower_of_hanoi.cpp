/*
Algorithm:

1. move n-1 disk from source to intermediate using destination
2. move nth disk from source to destination using intermediate
3. move n-1 disk from intermediate to destination using source

*/

#include <iostream>
#include <string>
using namespace std;
void toh(int n, string a, string b, string c)
{
    if (n == 1)
    {
        cout << "Move disks " << n << " from " << a << " to " << c << endl;
        return;
    }
    toh(n - 1, a, c, b);
    cout << "Move "
         << "disks " << n << " from " << a << " to " << c << endl;

    toh(n - 1, b, a, c);
}

int main()
{
    int disk_num;
    cout << "Enter the number of disk: " << endl;
    cin >> disk_num;

    toh(disk_num, "source", "intermediate", "destination");
}