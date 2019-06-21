// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #1 - Problem #1 - printOddNums

#include <iostream>
using namespace std;

/*
* Algorithm: Display the odd numbers that are in a given value
* 1. Take value of numbers and use for the function
* 2. Set the first odd number equal to 1
* 3. Run the given number paramter through while loop to display odd numbers in number parameter
* Input parameters: number (integer)
* Output (prints to screen): output odd values in order
* Returns: nothing
*/

void printOddNums(int n) {
    // declare odd as integer and set it to value (odd equal to 1 because odd numbers start at 1)
    int odd = 1;
    // while loop tp run through the given number parameter to list odd numbers in that parameter
    while (n > 0) {
        // output odd numbers
        cout << odd << endl;
        // set odd equal to equation to get next odd number in sequence
        odd = odd + 2;
        // set number equal to equation 
        n = n - 2;
    }    
}

int main() {
    // test 1
    // expected output: 1 3 5
    printOddNums(5);
    
    // endline
    cout << endl;
    
    // test 2
    // expected output: 1 3 5 7 9 11
    printOddNums(11);
}