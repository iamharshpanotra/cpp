#include <iostream>

using namespace std;

int main(){
    int n, sum = 0;

    cout << "Enter the value of n: " << endl;

    cin >> n;

    int i = 1;

    while(i <= n){
        sum += i;
        i++;
    }

    cout << "The sum of n natural numbers is: " << sum << endl;


    return 0;
}