#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    cout << "The number is: " << num << endl;

    // 1. Back up the original number before the loop modifies it
    int original_num = num;
    int reversed_num = 0;

    // 2. Loop to reverse the digits of the number
    while(num != 0){
        int remainder = original_num % 10;
        //cout << remainder << endl;
        int reversed_num = (reversed_num * 10) + remainder;
        //cout << reversed_num << endl;
        num = num / 10;
        //cout << num << endl;
    }

    // 3. Compare the original backup with the reversed number
    if (original_num == reversed_num){
        cout << original_num << " is a palindrome." << endl;
    }
    else {
        cout << original_num << " is not a palindrome." << endl;
    }

    return 0;
 
}