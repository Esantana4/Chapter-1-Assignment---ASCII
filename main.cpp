// Erik Santana
// 8/22/23
// CPMR 131 - Professor Q
/*
Description:
 This program has 3 options: 1 to convert ASCII Text To ASCII Numbers, 2 to convert a number into diffent bases(2 - 36)
 and 3, a description of statistics of binary files with numerical data inside of them.
 */

#include "input.h" // must be on top of the 3 main header files
#include <iostream> // must be on top of the 3 main header files
#include <string> // must be on top of the 3 main header files
#include <fstream> 
#include "ASCIITextToASCIINumbers.h"
#include "BaseConverter.h"
#include "DescriptiveStatistics.h"

using namespace std;

// main menu
void mainMenu();

int main()
{

    // program begins
    mainMenu();

    return 0;
}

// Pre-Conditon: no parameters
// Post-Condition: no return. displays main menu and calls specific functions for the case options
void mainMenu()
{

                                    // Main Menu

    cout << endl;
    cout << "\tCMPR131 - Chapter 1 Software Development by Erik Santana (8 / 22 / 23)";
    cout << "\n\t" << string(80, char(205)) << endl;
    cout << "\t1 > ASCII Text To ASCII Numbers" << endl;
    cout << "\t2 > Base Converter" << endl;
    cout << "\t3 > Descriptive Statistics" << endl;
    cout << "\n\t" << string(80, char(169));
    cout << "\n\t0 > exit" << endl;
    cout << "\n\t" << string(80, char(205)) << endl;

    // get user input/option of main menu
    int option = inputInteger("\n\tOption: ", 0, 3);

    // loop through main menu until user exits
    do
    {
        switch (option)
        {
        case 0: exit(1); break;
        case 1: system("cls"); option1(); break;
        case 2: system("cls"); baseConverterMenu(); break;
        case 3: system("cls"); descriptiveStatistics(); system("pause"); break;

        }

        // new line
        cout << "\n";

    } while (true);

}
