#include <iostream>
using namespace std;

int main() 
{
    int a, b;

    cout << "Enter two values: " << endl;

    cin >> a >> b; 

    cout << "Before swapping, the value of a is " << a << " and the value of b is " << b << endl;

    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "After swapping, the value of a is " << a << " and the value of b is " << b << endl;

    return 0;
}