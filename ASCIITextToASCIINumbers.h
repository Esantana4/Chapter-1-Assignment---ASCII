#pragma once

// Erik Santana
// 8/22/23
// CPMR 131 - Professor Q

#include <string>
#include <fstream>

// The mainMenu() function is to return back to the main menu from a sub menu. It is a necessary step. You need to add your own mainMenu to use this code.
// I called this function once in line 49, in the switch statement, in case 0:
void mainMenu();
void option1();
void displayConvertStringToBinary(string text);

// Pre-Conditon: no parameters
// Post-Condition: no return. sub menu from mainMenu(). A switch statement that runs each option in the sub menu.
void option1()
{

    // variable to hold the inputed string
    string textLine;

    // variable to hold file name
    string textFile;

    // the sub menu to keep running so long as the user permits
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
        cout << "\n\t0 > return to Main Menu"; // return to the main menu from sub menu
        cout << "\n\t" << string(80, char(205)) << endl;

        // get user input/option of sub menu 1. ASCII Text To ASCII Numbers
        int option = inputInteger("\n\tOption: ", 0, 4);

        switch (option)
        {

            // if user wants to return to main menu. but first the console is cleared
        case 0: system("cls"); mainMenu(); break;
        case 1:
        {

            // ask user to input a string 
            textLine = inputString("\n\tEnter a text line: ", true);

            // confirm to user that a string was accepted 
            cout << "\n\tString accepted." << endl;

        }break;

        case 2:
        {

            // Check if the textFile variable is empty before saving to file
            if (textLine == "")
            {
                cout << "\n\tERROR: empty binary text.\n";
            }
            else
            {

                // holds an empty value until it is converted
                textFile = textLine;

                // convert string to binary
                displayConvertStringToBinary(textLine);

                cout << endl;
            }

        }break;

        case 3:
        {

            // Check if the textFile variable is empty before saving to file
            if (textFile == "")
            {
                cout << "\n\tERROR: empty binary text.\n";
            }
            else
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

                // confirm data was written to the file
                cout << "\n\n\tData has been written to " << textFile << endl;

                // display/confirm the data that was just saved
                displayConvertStringToBinary(textLine);

            }

        }break;

        case 4:
        {

            // open binary file
            // creating an input file stream named inputFile and opening a file named textFile in binary mode
            ifstream inputFile(textFile, ios::binary);

            // check for file not opening
            if (!inputFile.is_open()) {
                cout << "Error opening file for reading!" << endl;
                system("pause");
                system("cls");
                option1();
            }
            else if (textFile == "")
            {
                cout << "\nFile did not open.\n";
            }
            else
            {

                // confirm which file was opened
                cout << "\n\n\tData read from " << textFile << endl << endl;

                // display/confirm what was written to the file
                displayConvertStringToBinary(textLine);

                // close file
                inputFile.close();

                // reset the user input text variables to check for empty inputs. If the user runs the program again they won't be able to skip around the options.
                textLine = "";
                textFile = "";
            }

        }break;

        }

        // new line
        cout << "\n";

    } while (true); // end of do-while loop

}

// Pre-Condition: The text varibale needs to be a string. Then the string(text) is converted into Binary
// Post-Condition: no return value
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
