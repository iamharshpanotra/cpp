#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Enter a number: ";

    if (!(cin >> num)) {
        cout << "Input failed!" << endl;
        return 1;
    }

    if (num % 2 == 0)
        cout << "The number is even." << endl;
    else
        cout << "The number is odd." << endl;

    return 0;
}