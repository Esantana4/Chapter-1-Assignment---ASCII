// Erik Santana
// 8/22/23
// CPMR 131 - Professor Q

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "input.h"

using namespace std;

int mainMenu();
void option1();
void option2();
void option3();
string convertDecimalNumber(int, int);
void displayConvertStringToBinary(string text);


// test - ***********************************
int main()
{

    mainMenu();

	return 0;
}

// Pre - Conditon
//Post-Condition
int mainMenu()
{

    cout << endl;
    cout << "\tCMPR131 - Chapter 1 Software Development by Erik Santana(8 / 22 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1 > ASCII Text To ASCII Numbers" << endl;
    cout << "\t2 > Base Converter" << endl;
    cout << "\t3 > Descriptive Statistics" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    int option = inputInteger("\n\tOption: ", 0, 3);

    do
    {
        switch (option)
        {
        case 0: exit(1); break;
        case 1: option1(); break;
        case 2: option2(); break;
        case 3: option3(); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);

}

//Pre-Conditon
//Post-Condition
void option1()
{
    // variable to hold the inputed string
    string textLine;

    // variable to hold file name
    string textFile;

    do
    {

        // 1. Sub Menu
        cout << "\n\t1 > ASCII Text To ASCII Numbers";
        cout << "\n\t" << string(80, char(205)) << endl;
        cout << "\n\t1 > Enter a text string";
        cout << "\n\t2 > Convert the text string to ASCII numbers";
        cout << "\n\t3 > Save the converted ASCII numbers into a binary file";
        cout << "\n\t4 > Read the binary file";
        cout << "\n\t" << string(80, char(169));
        cout << "\n\t0 > return to Main Menu";
        cout << "\n\t" << string(80, char(205)) << endl;

        // get user input/option of sub menu 1. ASCII Text To ASCII Numbers
        int option = inputInteger("\n\tOption: ", 0, 4);

        switch (option)
        {

            // if user wants to return
        case 0: system("cls"); mainMenu(); break;
        case 1:
        {

            // ask user to inout a string 
            textLine = inputString("\n\tEnter a text line: ", true);

            // confirm to user that string was accepted 
            cout << "\n\tString accepted." << endl;

        }break;

        case 2:
        {
            // convert string to binary
            displayConvertStringToBinary(textLine);

            cout << endl;

        }break;

        case 3:
        {

            // store file name in textFile, that includes spaces
            textFile = inputString("\n\tEnter the name of the binary file, to save your binary code: ", false);

            // create ofstream named outputFile that writes to a binary file named textFile 
            ofstream outputFile(textFile, ios::binary);

            // check if file exists
            if (textFile.empty()) {
                cout << "Error opening file for writing!" << endl;
                system("pause");
                option1();
            }

            // Writing data to the binary file   
            for (int i = 0; i < textLine.size(); i++)
            {
                outputFile << int(textLine[i]) << " ";
            }

            // close file
            outputFile.close();

            // display data that was saved
            displayConvertStringToBinary(textLine);

            // confirm data was written to the file
            cout << "\n\n\tData has been written to " << textFile << endl;

        }break;

        case 4:
        {

            // creating an input file stream named inputFile and opening a file named textFile in binary mode
            ifstream inputFile(textFile, ios::binary);

            // open binary file
            inputFile.open(textFile, ios::binary);

            // check for file not opening
            if (!inputFile.is_open()) {
                cout << "Error opening file for reading!" << endl;
                system("pause");
                system("cls");
                option1();
            }

            // confirm which file was opened
            cout << "\n\n\tData read from " << textFile << endl << endl;

            // display each letter in the string in binary
            displayConvertStringToBinary(textLine);

            // close file
            inputFile.close();


        }break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";

    } while (true);

}

//Pre-Conditon
//Post-Condition
void option2()
{
    int decimalNumber = 0;
    int base = 0;

    do {

        cout << "\n\t2> Base Converter";
        cout << "\n\t" << string(80, char(205)) << endl;
        cout << "\n\t1 > Enter an integer number (base 10)";
        cout << "\n\t2 > Specify and convert base";
        cout << "\n\t3 > Display all converted bases (2..36)";
        cout << "\n\t" << string(80, char(169));
        cout << "\n\t0 > return to Main Menu";
        cout << "\n\t" << string(80, char(205)) << endl;

        int option = inputInteger("\n\tOption: ", 0, 3);

        switch (option)
        {

        case 0: system("cls"); mainMenu(); break;
        case 1: 
        {
            decimalNumber = inputInteger("Enter an integer number of base 10: ", true);

        }break;
        case 2: 
        {
            cout << "Your number is " << decimalNumber << "." << endl;

            base = inputInteger("Enter the base to convert your number to (2..36): ", 2, 36);
            //string binaryNumber = "";

            if (base >= 2 && base <= 32)
            {
                convertDecimalNumber(decimalNumber, base);
            }


            //cout << binaryNumber << endl;


            //string binaryNumber = "";

            //while (decimalNumber > 0) {
            //    int remainder = decimalNumber % 2;
            //    binaryNumber = to_string(remainder) + binaryNumber;
            //    decimalNumber /= 2;
            //    
            //}

            //cout << binaryNumber << endl;

            //int digit = 0;

            // While the decimal(base 10) number is greater than 0
            // update digit and baseNum
            // digit = digit * 10 + the remainder of baseNum / decimalNumber
            // baseNum = the quotient of baseNum / decimalNumber
            // Then baseNum is updated in the condition in the while statement.
            //while (baseNum > 0) {
            //    digit = digit * 10 + (baseNum % decimalNumber);
            //    baseNum /= decimalNumber;
            //}

            //cout << digit << endl;


        }break;

        case 3:{

            int baseArray[]  = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36};
            
            // Dividing the total size of an array by a single element gives you the number of elements in an array
            int numBases = sizeof(baseArray) / sizeof(baseArray[0]);

            for (int i = 0; i < numBases; i++)
            {
                base = baseArray[i];
                
   // not properly working *****************************************************************
                string answer = convertDecimalNumber(decimalNumber, base);

                // Convert string to int using stoi to compare values
                int convertedNumber = stoi(answer);
                cout << answer << endl;
                if (baseArray[i] == convertedNumber)
                    cout << "N\n";
            }

        }break;

        }



    } while (true);

}

//Pre-Conditon
//Post-Condition
void option3()
{


}

// Pre-Condition: 
// Post-Condition: 
void displayConvertStringToBinary(string text)
{

    // display title
    cout << "\n\tASCII: " << endl;

    // loop through string and convert each letter into binary
    for (int i = 0; i < text.size(); i++)
    {
        cout << "\t" << static_cast<int>(text[i]) << " ";
    }
}

string convertDecimalNumber(int decimalNum, int _base)
{
    //int base = 0;

    // Using a string for concatination of the remainders
    // To store conversion
    string binaryNumber = "";

    while (decimalNum > 0)
    {

        // remainder keeps track of all remainders
        int remainder = decimalNum % _base;

        // Concatination of the remainder and binaryNumber to store the total conversion.
        binaryNumber = to_string(remainder) + binaryNumber;

        // decimalNum keeps track of the quotient between the number being converted and the base dividing into the decimal number.
        // and this while-loop continues while decimalNum > 0
        decimalNum /= _base;


    }

        // Display the concatinated remaninders/conversion
        return binaryNumber;
        //if (binaryNumber > "10")
        //    cout << "\N";
 
}