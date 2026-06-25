#include <iostream>
using namespace std;

int main() {
    // int salary = 20000;
    // int* address = &salary;

    // cout<< "The salary is: " << salary << endl;

    // cout << "The address where salary is stored is: " << address << endl;

    // cout << "The value by pointer is: " << *address << endl;

    // string team[] = {"Shashank", "Himanshu", "Shubhendra", "Shashikant", "Harsh", "Shubham", "Aman"};

    // cout << team[4] << endl;

    int prices[] = {100, 200, 300, 400, 500};
    int* ptr = prices;

    int numbers[5] = {1, 2, 3, 4, 5};

    cout << numbers << endl;
    cout << &numbers[0] << endl;
    cout << numbers[3] << endl;

    return 0;
}