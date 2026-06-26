#include <iostream>
using namespace std;

int doSum(int a, int b){
    int sum = a + b;
    return sum;
}
int main() {
    int result = doSum(5, 10);
    cout << "The sum is: " << result << endl;

    return 0;
}