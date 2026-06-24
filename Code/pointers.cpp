#include <iostream> 
using namespace std;

int main() {

    int value = 42;
    int* ptr = &value;
    
    cout << "Value: " << value << std::endl;
    cout << "Address: " << ptr << std::endl;
    cout << "Value via pointer: " << *ptr << std::endl;
    return 0;
}