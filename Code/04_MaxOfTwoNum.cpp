#include <iostream>

using namespace std;

int main(){
    int a, b;

    cout <<"Enter the two numbers: " << endl;

    cin >> a >> b;

    if (a>b){
        cout<< "The larger number is: " << a << endl;
    }
    else if(b>a){
        cout<< "The larger number is: " << b << endl;
    }
    else {
        cout <<"Both the numbers are equal."<< endl;
    }

    return 0;
}