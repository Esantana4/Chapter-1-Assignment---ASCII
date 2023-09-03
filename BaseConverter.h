#pragma once

// Credit: 
// Saul Merino & John Kim - Base Converter


/*
*
Hello this is a base convertion calculator written in C++ This was written by Saul Merino and John Kim. Special thanks to Erik Santana for QA checks.

There are three options that will be given once it is called. The user is prompted to selected their option, or exit out of this calcualtor.

The user will be given a choice on what options to pick. in the first option, the user is prompted.
to enter an integer value, either positive or negative, in the decimal system. This will be stored for later use.

Note that if the user does not input an integer for calculation, then the program will prompt the user to enter one before continuing.

In the second option, the user is prompted to input a base from from binary [2], to all the way to hexatrigesimal [36]
then it will display the converted number to the appropriate base with characters and negative numbers, if needed.

In the third option, the program will automaticly calculate and display all possible  base conversions
from binary [2], to all the way to hexatrigesimal [36] in one list with the integer the user inputed.

*/


#include <iomanip>
#include <cmath> //absolute value 
#include <cctype> //for the toupper validation

void baseConverterMenu(); //Part 2 Main menu
int baseConverterMenuOption(); //Introduction UI
int newIntInput(); // Option 1 in UI
void baseConversionSingle(int num1); //Option 2 in UI
void baseConversionAll(int num1); // Option 3 in UI

//This is the Main menu for Part 2. It will return back to the Assignment 1 once it is done.
// Precondition: None
// Postcondition: returns the called function, depending on what case input was selected.
void baseConverterMenu()
{
	int num1;
	bool numInput = false;
	do
	{
		switch (baseConverterMenuOption())
		{
		case 0: system("cls"); mainMenu(); break;
		case 1: num1 = newIntInput(); numInput = true; break;
		case 2: if (!numInput) { cout << "ERROR - No integer has been entered."; break; } baseConversionSingle(num1); break;
		case 3: if (!numInput) { cout << "ERROR - No integer has been entered."; break; } baseConversionAll(num1); break;
		default: cout << "ERROR - Invalid option. Please Enter A, B, C, or 0."; break;
		}
		cout << endl;
		system("pause");
	} while (true);
}

//This is the intro text for the Main Menu for Part 2
// Precondition: None
// Postcondition: Returns a (char), or an uppercase of the option (char)
int baseConverterMenuOption()
{
	system("cls");
	cout << "CMPR131 Part 2. Base Converter" << endl;
	cout << "2: Base Converter" << endl;
	cout << string(100, char(205)) << endl;

	cout << "1. Enter an Integer Number (Base 10)" << endl;
	cout << "2. Specify the converting Base" << endl;
	cout << "3. Display All Converted Bases" << endl;
	cout << string(100, char(196)) << endl;

	cout << "0. Return" << endl;
	cout << string(100, char(205)) << endl;
	int option = inputInteger("Option : ", 0, 3);
	return option;
}

//This is where the user can choose what base to calculate their number. It is limited in range from binary [2] all the way to hexatrigesimal [36]
// Precondition: Valid Integer
// Postcondition: Returns the Integer and its converted Base
int newIntInput()
{
	return inputInteger("Enter An Integer in Base 10: ");
}

//This is where the user can choose what base to calculate their number. It is limited in range from binary [2] all the way to hexatrigesimal [36]
// Precondition: Valid Integer
// Postcondition: Returns the Integer and its converted Base
void baseConversionSingle(int num1)
{

	int base = inputInteger("Enter the base to convert your number to (2..36): ", 2, 36);	//this is the intro and asks for what base to calculate in
	string binaryNumber = "";
	char hex;					//this is to hold an integer-turned to char for string input.
	int tempNum = num1;

	do
	{
		int remainder = abs(num1) % base;

		num1 /= base;

		if (remainder > 9)																	//this is where numeric values that exteed our decimal system get translated to the appropiate base.
		{
			hex = remainder + 55;															//the 'exteeded' value is converted to the ascii binary code. For example 
			string hexNum(1, hex);															// the array is advanced
			binaryNumber.insert(0, hexNum);													// the now converted value is then added to the string
		}
		else //if the numeric value was between 0-9, it directly puts it in.
		{
			binaryNumber.insert(0, to_string(remainder));
		}

	} while (abs(num1) >= base);
	if (abs(num1) > 9)
	{
		hex = abs(num1) + 55;
		string hexNum(1, hex);
		binaryNumber.insert(0, hexNum);
		if (tempNum < 0)//if the integer inputed was negative, then the negative sign would be added at the end
		{
			binaryNumber.insert(0, "-");
		}
	}
	else if (num1 != 0) // this is if the number is too small and can fit in the base.
	{
		binaryNumber.insert(0, to_string(num1));
	}
	else if (tempNum < 0 && num1 == 0)//if the integer inputed was negative, then the negative sign would be added at the end
	{
		binaryNumber.insert(0, "-");
	}

	cout << tempNum << " (Base of 10) = " << binaryNumber << " (Base of " << base << ")" << endl;
}

//This is where the program calculates their number in all the bases. It lists out all the base conversion from binary [2], to all the way to hexatrigesimal [36] in one list.
// Precondition: Integer (Positve or Negative)
// Postcondition: Outputs the Integer and the list of all converted Bases
void baseConversionAll(int num1)
{

	int tempNum = num1; //this is just to hold the  for a moment.
	char hex;
	cout << "Your number is " << num1 << "." << endl;
	string binaryNumber = "";
	for (int base = 2; base <= 36; base++)
	{
		num1 = tempNum;
		do
		{
			int remainder = abs(num1) % base;
			num1 /= base;
			if (remainder > 9)
			{
				hex = remainder + 55;
				string hexNum(1, hex);
				binaryNumber.insert(0, hexNum);
			}
			else
			{
				binaryNumber.insert(0, to_string(remainder));
			}
		} while (abs(num1) >= base);
		if (abs(num1) > 9)
		{
			hex = abs(num1) + 55;
			string hexNum(1, hex);
			binaryNumber.insert(0, hexNum);
			if (tempNum < 0)
			{
				binaryNumber.insert(0, "-");
			}
		}
		else if (num1 != 0)
		{
			binaryNumber.insert(0, to_string(num1));
		}
		else if (tempNum < 0 && num1 == 0)//if the integer inputed was negative, then the negative sign would be added at the end
		{
			binaryNumber.insert(0, "-");
		}

		cout << binaryNumber << " (Base of " << base << ")" << endl;
		binaryNumber.clear();
	}
}
