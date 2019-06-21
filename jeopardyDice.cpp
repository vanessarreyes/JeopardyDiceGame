// CS1300 Spring 2019
// Author: Vanessa Reyes
// Recitation: 205 - Punith Patil
// Cloud9 Workspace Editor Link: https://ide.c9.io/vanessarreyes/csci1300
// Project #1 - Problem #3 - jeopardyDice

#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
// Pseudocode:
// ------------------------------------------------------------------------------------------------
//
// 1. I want to figure out what my three functions will hold.
// 2. I know that there are two players, therefore, I can make a function for each of their turns
// 3. My last function can be to determine the winner of the game
// 4. Now that I have my three function ideas, I can figure out what will go in my game function
//      a. I want to have my game function display the name of the game as well as call my other functions
//         to have the game play
//      b. So I know that the player will start first and then the computer second. Therefore, I will call
//         the player function first then the computer
//      c. I also want to test the total values of each player in game function so I will use a loop
//      d. I also want to test whether the player wins since the player goes first. Therefore,
//         I will use an if statement to test if player wins before runnung computer turn
//      e. Once a player reaches 80, I want the loop to be exited and the winner function to be called
//
//  function {
//  declare playerTotal
//  declare computerTotal
//  output message for game title
//  while loop {
//    call player turn function
//    set total from turn equal to player total
//    display both player scores
//    call computer turn function
//    set total from turn total to computer total
//    display both player scores
//      }
//  call winner function
//  }
//
// 5. I need to figure out what will go in my player turn function
//      a. I want to declare variables that will be used in function
//      b. I want to display messages saying player turn
//      c. I want to ask user if they want to roll the dice
//      d. Use a loop to run the dice roll if the player says yes to roll
//      e. Set rules (if statements) to make categories for values of the dice roll (game rules for rolling)
//      f. Output messages and set turn total to values based on each category
//      g. Ask the user if they want to continue rolling if roll isn't 2,4,5
//      h. Return turnTotal value at the end
//
//  function    {
//  declare turnTotal
//  declare roll_value
//  output message
//  output message 
//  allow user to input yes/no
//  set input to case insensitive
//  while loop {
//      set roll value equal to the function roll value 
//      output message 
//      if statement{
//          turnTotal value
//          output message
//          y/n char
//      }
//      else if {
//          turnTotal value
//          output message
//          y/n char
//      }
//      else {
//          turnTotal value
//          output message
//          y/n char
//          }
//      }
//      return turnTotal
//  }
// 
// 6. I need to figure out what will go in my computer turn function
//      a. I want to declare variables that will be used in the function
//      b. I want to display message saying computer turn
//      c. Use a loop to roll dice until computer has turnTotal greater than or equal to 10
//      d. Set rules (if statements) to make categories for values of the dice roll (game rules for rolling)
//      e. Output messages and set turn total to values based on each category
//      f. Return turnTotal value at the end
//
//  function    {
//  declare turnTotal
//  declare roll_value
//  output message
//  while loop {
//      set roll value equal to the function roll value 
//      output message 
//      if statement{
//          turnTotal value
//          output message
//          return turnTotal
//      }
//      else if {
//          turnTotal value
//          output message
//          return turnTotal
//      }
//      else {
//          turnTotal value
//          output message
//          }
//      }
//      return turnTotal
//  }
//
// 7. I need to figure out what will go in my winner function
//      a. Take in both player totals to test
//      b. If statement to test which player total went over 80
//      c. Based on who won, output a message stating winner
//
//  function {
//      if (test one player score) {
//          output winner message
//      }
//      else {
//          output winner message
//      }
//  }
//
// 8. Now that I have all my functions determined, I will then code them up
//
///////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
using namespace std; 

/**
 * rollDie 
 * returns a random integer between 1 and 6, works as rolling a dice.
 * return value, int number (1-6)
 */

int rollDie()
{
	return random() % 6 + 1; 
}

/*
* Algorithm: Runs player's turn to roll dice including rules
* 1. Declare variables used for function
* 2. Output message stating it is player's turn
* 3. Ask the player if they want to roll the dice
* 4. If they input no, the die doesn't get rolled and the function ends. Otherwise, if input yes
*    then the die gets rolled (from roll_dice function)
* 4. Output the value from that dice roll 
* 5. Test value from roll to determine which rule it falls under
* 6. Based on rule it falls under, output what the turn total is 
* 7. Ask the player to roll again. If input no, end the function. If they say yes, roll the dice
*    again. Ask the user if they want to continue to roll unless they roll a value of 2,4,5 or input no.
* Input parameters: none
* Output (prints to screen): 
*       "It is now human's turn"
*       
*       "Do you want to roll a dice (Y/N)?:"
*       <y_or_n input>
*       "You rolled a " <roll_value>
*       "Your turn total is " <turnTotal>
*       "Do you want to roll again (Y/N)?:"
*       <y_or_n input>
* Returns: turnTotal (integer)
*/

int playerTurn() {
    // declare turnTotal equal to 0
    int turnTotal = 0;
    // declare roll_value equal to 0
    int roll_value = 0;
    // declare y_or_n as a character
    char y_or_n;
    // endline
    cout << endl;
    // output message 
    cout << "It is now human's turn" << endl << endl;
    // output message 
    cout << "Do you want to roll a dice (Y/N)?:" << endl;
    // allow user to input either yes or no
    cin >> y_or_n;
    /// set char in y_or_n to lower case for case insensitive
    y_or_n = tolower(y_or_n); 
    // while loop that tests whether character y_or_n is 'y'
    while (y_or_n == 'y') {
        // set the roll value to the function that rolls the dice and gets value 
        roll_value = rollDie();
        // output message with roll_value 
        cout << "You rolled a " << roll_value << endl;
        // if statement that tests whether the roll value is equal to 2 or if the roll value is equal to 5
        if (roll_value == 2 or roll_value == 5) {
            // declare turnTotal equal to 0
            turnTotal = 0;
            // output message with turn total
            cout << "Your turn total is " << turnTotal << endl;
            // declare y_or_n equal to 'n' to exit loop
            y_or_n = 'n';
        }
        // else if check if roll value is equal to 4
        else if (roll_value == 4) {
            // decalare turnTotal equal to 15
            turnTotal = 15;
            // output message with turnTotal
            cout << "Your turn total is " << turnTotal << endl;
            // set y_or_n to 'n' which exits loop
            y_or_n = 'n';
        }
        // all other values
        else {
            // set turnTotal equal to turnTotal plus roll value to get new turnTotal
            turnTotal = turnTotal + roll_value;
            // output message with turnTotal
            cout << "Your turn total is " << turnTotal << endl;
            // output message 
            cout << "Do you want to roll again (Y/N)?:" << endl;
            // allow user to input either 'y' or 'n'
            cin >> y_or_n;
            // set char in y_or_n to lower case for case insensitive
            y_or_n = tolower(y_or_n); 
        }
    }
    // return turnTotal value
    return turnTotal;
}

/*
* Algorithm: Runs computer's turn to roll dice including rules
* 1. Declare variables used for function
* 2. Output message stating it is computer's turn
* 3. Have computer roll dice (from roll_dice function) 
* 4. Output the value from that dice roll 
* 5. Test value from roll to determine which rule it falls under
* 6. Based on rule it falls under, output what the turn total is 
* 7. Allow computer to roll again until the computer's turn total is greater than or equal to 10
*    or if a roll value from dice wasn't 2,4,5
* Input parameters: none
* Output (prints to screen): 
        "It is now computer's turn"
        
*       "Computer rolled a " <roll_value>
*       "Computer turn total is " <turnTotal>
* Returns: turnTotal (integer)
*/

int computerTurn () {
    // declare turnTotal equal to 0
    int turnTotal = 0;
    // declare roll_value equal to 0
    int roll_value = 0;
    // endline
    cout << endl;
    // output message 
    cout << "It is now computer's turn" << endl << endl;
    // while loop that runs if and only if turnTotal is less than 10
    while (turnTotal < 10) {
        // set the roll value to the function that rolls the dice and gets value
        roll_value = rollDie();
        // output message with roll value
        cout << "Computer rolled a " << roll_value << endl;
        // if statement that tests whether the roll value is equal to 2 or if the roll value is equal to 5
        if (roll_value == 2 or roll_value == 5) {
                // declare turnTotal equal to 0
                turnTotal = 0;
                // output message with turn total
                cout << "Computer turn total is " << turnTotal << endl;
                // return turnTotal and exit
                return turnTotal;
            }
            // else if check if roll value is equal to 4
            else if (roll_value == 4) {
                // decalare turnTotal equal to 15
                turnTotal = 15;
                // output message with turnTotal
                cout << "Computer turn total is " << turnTotal << endl;
                // return turnTotal and exit
                return turnTotal;
            }
            // all other values
            else {
                // set turnTotal equal to turnTotal plus roll value to get new turnTotal 
                turnTotal = turnTotal + roll_value;
                // output message with turnTotal
                cout << "Computer turn total is " << turnTotal << endl;
            }
    }
    // return turnTotal value
    return turnTotal;
}

/*
* Algorithm: Take values of playerTotal and computerTotal to determine which one is the winner
* 1. Take value of playerTotal and computrTotal and use it in function
* 2. Test whether which one of the values is greater than 80
* 3. The value that is greater than 80 outputs a message that declares the winner
* Input parameters: playerTotal (integer), computerTotal (integer)
* Output (prints to screen): output changes by category:
*       if player wins, output is "Congratulations! human won this round of Jeopardy Dice!"
*       if computer wins, output is "Congratulations! computer won this round of Jeopardy Dice!"        
* Returns: nothing
*/

void winner (int playerTotal, int computerTotal) {
    // if statement that checks if playerTotal is greater than 80
    if (playerTotal > 80) {
        // endline
        cout << endl;
        // output message
        cout << "Congratulations! human won this round of Jeopardy Dice!" << endl;
    }
    // all other values
    else {
        // endline
        cout << endl;
        // output message
        cout << "Congratulations! computer won this round of Jeopardy Dice!" << endl;
    }
}
 
 /*
* Algorithm: starts the game
* 1. Declares some values that are going to be used in the game and sets them equal to 0
* 2. Output starting game message
* 3. Start the player's turn
* 4. After player's turn, output the total points of the human and computer 
* 5. Start the computer's turn if player hasn't reached winning score
* 6. After the computer's turn, output the total points of the human and computer
* 7. Both the players and computer keep having a turn until one of them reach winning score
* 8. Call function to output the winner 
* Input parameters: none
* Output (prints to screen): 
*       "Welcome to Jeopardy Dice!"
*       playerTotal function outputs
*       "computer: " <computerTotal>
*       "human: " <playerTotal>
*       computerTotal function outputs
*       "computer: " <computerTotal>
*       "human: " <playerTotal>
*       winner function outputs
* Returns: nothing
*/

void game() {
    // declare playerTotal equal to 0
    int playerTotal = 0;
    // declare computerTotal equal to 
    int computerTotal = 0;
    // output message
    cout << "Welcome to Jeopardy Dice!" << endl;
    // while loop runs if and only if playerTotal is less than 80 and if computerTotal is less than 80
    while (playerTotal < 80 and computerTotal < 80) {
        // set playerTotal equal to playerTotal plus the function playerTurn that returns the value of turnTotal (playerTotal + turnTotal)
        playerTotal = playerTotal + playerTurn();
        // output message with computerTotal
        cout << "computer: " << computerTotal << endl;
        // output message with playerTotal
        cout << "human: " << playerTotal << endl;
        // if statement that checks whether is playerTotal is less than 80 (will allow computer's turn if player hasn't won yet)
        if (playerTotal < 80) {
            // set computerTotal equal to computerTotal plus the function of computerTurn that returns turnTotal (computerTotal + turnTotal)
            computerTotal = computerTotal + computerTurn();
            // output message with computerTotal
            cout << "computer: " << computerTotal << endl;
            // output message with playerTotal
            cout << "human: " << playerTotal << endl;
        }
    }
    // call winner function using variables playerTotal and computerTotal
    winner(playerTotal, computerTotal);
}


int main()
{
    srand(123);
	// start the game!
	game();
	return 0;
}