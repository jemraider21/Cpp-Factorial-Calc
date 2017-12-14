/*
Jared Morris
Version 1.0
Created: December 13, 2017
Title: Jemraider Test

Objective
Qucik Overview
Program will find the factorial of a number entered by the user and check for all conditions
Specific Overview
To find the factorial of a number, multiply the given number by every number below it
Ex: 5! = 1*2*3*4*5 = 120
Ask the user for a number they want to find the factorial of
If the number is less than or equal to 0, print out an error and loop back to the beginning
Use a for loop starting at 1 that multiplies "i" by "Factorial"
Print out the factorial of the number and all numbers
*/

#include <iostream>

using namespace std;

//Declare global constants

//Declare structures

//Declare prototypes
void welcomeUser();
int askUser();
int checkNumber(int);
void calculateFactorial(int);
int continueProgram();
void conclusion();

int main() {

	//Initialize variables
	int userNumber;
	int looper;

	//Start of program
	welcomeUser();

	do {
		userNumber = askUser();
		if (userNumber == 0) {
			cout << "0! = 1. Don't ask, that's just what I'm being told.\n\n";
		}
		else {
			calculateFactorial(userNumber);
		} //End of if else statement
		cout << endl;
		looper = continueProgram();
		cout << endl << endl;
	} while (looper == 0);
	conclusion();

	//Ending blurb
	system("pause");
	return 0;

}//End of main method






 //Welcome the user to the program
void welcomeUser() {

	cout << "\t\tFactorial Number Calculator\n\n\n";
	cout << "Hello user! This calculator is designed to find the factorial of a number!\n"
		<< "For example, the factorial of 5, which is 1*2*3*4*5, or 5!, is 120\n";
	cout << "You ready? Let's begin!\n\n";

}//End of welcomeUser function







 //Ask the user for a positive real number. Send number to checkNumber once obtained
int askUser() {

	//Initialize variables
	int userInput;
	int userCheck;
	int looper;

	do {
		cout << "Please enter a real positive numer: ";
		cin >> userInput;
		userCheck = checkNumber(userInput); //If returned number is 1, return userInput. If 0, loop back to the beginning of the function
		if (userCheck == 0) {
			cout << "I'm sorry, that number is not valid. Please try again...\n";
			looper = 0;
		}
		else {
			looper = 1;
		}
	} while (looper == 0);
	return userInput;

}//End of askUser function






 //Check to see if the user generated number userInput is a real positive number
 //If checker is 1, then the number was greater than 0. If checker is 0, the number is less than or equal to 0.
int checkNumber(int userInput) {

	//Initialize variables
	int checker;

	if (userInput >= 0) { //generate 1
		checker = 1;
	}
	else {
		checker = 0;
	}

	return checker;

}//End of userInput function






 /*
 Use a for loop to calculate the factorial
 Int "i" will start off at 1, and then continue up until it reaches the user generated number

 */
void calculateFactorial(int userNumber) {

	//Initialize variables
	int factorialNumber = 1;

	cout << "Here is the factorial of " << userNumber << endl << endl;
	cout << userNumber << "! = ";
	for (int i = 1; i <= userNumber; i++) {
		if (i < userNumber) { //If "i" is less than the number, print out " num * ", then multiply "factorialNumber" by "i"
			cout << i << " * ";
			factorialNumber = factorialNumber * i;
		}
		else { //If "i" is equal to number, print out "num = ", then multiply "facotrialNumber" by "i"
			cout << i << " = ";
			factorialNumber = factorialNumber * i;
		}
	}//End of for loop
	cout << factorialNumber << endl;

}//End of calculateFactorial function






 /*
 Ask the user if they want to type in another number.
 If yes, send back 0, which will loop the program again.
 If no, send back 1, which will exit the main function loop and go to conclusion function
 */
int continueProgram() {

	//Initialize variables
	int userChoice;
	int theChoice;
	int looper;

	cout << "Do want to enter a new number?\n"
		<< "1. Yes, I want to enter a new number\n"
		<< "2. No, I would like to leave the calculator\n";
	do {
		cout << "Please make your selection: ";
		cin >> userChoice;
		if (userChoice == 1) { //Loop the program from the beginning
			theChoice = 0;
			looper = 1;
		}
		else if (userChoice == 2) { //Break the program's loop and finish the program
			theChoice = 1;
			looper = 1;
		}
		else { //Loop back to beginning of function because user input an invalid number
			cout << "I'm sorry, that's not a valid response. Please try again...\n";
			looper = 0;
		}
	} while (looper == 0);
	return theChoice;
} //end of continueProgram function






  //Say goodbye to the user
void conclusion() {

	cout << "Thank you for trying out the fractorial calculator! I hope to see you again soon!\n\n\n";

}//end of conclusion function