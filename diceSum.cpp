// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #1 - Problem #2 - diceSum

#include <iostream>
using namespace std;

/* rollDie
 * returns a random integer between 1 and 6,
 * works as rolling a die.
 * return value, int number (1-6)
 */
 
int rollDie()
{
return random() % 6 + 1;
}

/*
* Algorithm: Take a value for a desire sum and roll 2 die until their sum is equal to the desired sum
* 1. Take value of desired sum and use for the function
* 2. Test whether the desired sum is in range, if it isn't output message 
* 3. If desired sum is in range, then roll the 2 die and add their sums till it equals the desire sum
* Input parameters: sum (integer)
* Output (prints to screen): "The desired sum should be between 2 and 12" if sum is not in range
*                           displays the values of the 2 die rolled
*                           displays that desired sum was hit and in number of rolls done
* Returns: nothing
*/

void diceSum(int sum) {
    // if statement to check if the sum value is inbetween 2 and 12
    if (sum < 2 or sum > 12) {
        // output message
        cout << "The desired sum should be between 2 and 12" << endl;
    }
    // for all other values
    else {
        // decalare roll sum equal to 0
        int roll_sum = 0;
        // declare number of rolls equal to 0
        int n_of_rolls = 0;
        // while loop to roll the 2 die till their sum equals desired sum 
        while (sum != roll_sum) {
            // declare roll 1 to call function to get first roll value
            int roll_1 = rollDie();
            // declare roll 2 to call function to get second roll value
            int roll_2 = rollDie();
            // output message with roll values
            cout << "You rolled a " << roll_1 << " and a " << roll_2 << endl;
            // set roll sum equal to the 2 die value
            roll_sum = roll_1 + roll_2;
            // add 1 to the number of rolls done
            n_of_rolls = n_of_rolls + 1;
        }
    // output message with sum value and number of rolls done
    cout << "Got a " << sum << " in " << n_of_rolls << " rolls!" << endl;
        
    }
}

int main() {
    // test 1
    /* expected output: 
    You rolled a 2 and a 5
    You rolled a 4 and a 2
    You rolled a 6 and a 2
    You rolled a 5 and a 1
    You rolled a 4 and a 2
    You rolled a 3 and a 2
    Got a 5 in 6 rolls!
    */
    diceSum(5);
    
    // endline
    cout << endl;
    
    // test 2
    /* expected output:
    You rolled a 3 and a 2
    You rolled a 6 and a 5
    You rolled a 1 and a 1
    You rolled a 5 and a 5
    Got a 10 in 4 rolls!
    */
    diceSum(10);
}