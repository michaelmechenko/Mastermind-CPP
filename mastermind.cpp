#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void correctguesses(int array[], int arrayguess[], int &right, int &wrong); //Prototype

int main()
{
    srand(time(0));                                                           //Initializes random number generator
    int secretcode[4] = {rand() % 10, rand() % 10, rand() % 10, rand() % 10}; //Creates code the player has to determine

    cout << "You've approached the guarded safe, and you only have twelve guesses to crack the code." << endl; //Greeting
    cout << "The code is four digits long, with the range of numbers being 0-9." << endl;

    int codesum = 0;
    for (int i = 0; i < 4; i++)
    {
        codesum = codesum + secretcode[i]; //Takes sum of arguments within array
    }
    cout << endl
         << "The sum of the integers within the code is: " << codesum << endl; //Outputs sum to screen

    int numguesses = 12;

    for (int i = 0; i < numguesses; i++) //Loops while number of guesses is less than 12
    {
        cout << endl
             << "Please enter your guess as four digits separated by a space: ";
        int guesscode[4]; //Initializes user's guess
        for (int i = 0; i < 4; i++)
        {
            cin >> guesscode[i]; //User inputs their guess
        }

        int guesscode_copy[4];
        for (int i = 0; i < 4; i++)
        {
            guesscode_copy[i] = guesscode[i];
        }

        int secretcode_copy[4];
        for (int i = 0; i < 4; i++)
        {
            secretcode_copy[i] = secretcode[i];
        }

        int correctlocation = 0;                                                             //Initializes right number/right location
        int incorrectlocation = 0;                                                           //Initializes right number/wrong location
        correctguesses(guesscode_copy, secretcode_copy, correctlocation, incorrectlocation); //Sends the code, user's guess,
                                                                                             //variables holding correct number correct location/correct number incorrectlocation
                                                                                             //to void function

        if (guesscode[0] == secretcode[0] && guesscode[1] == secretcode[1] && guesscode[2] == secretcode[2] && guesscode[3] == secretcode[3]) //If the guessed code is equal to the actual code, output message and end game
        {
            cout << endl
                 << "You've cracked Jeff Goldblum's safe!" << endl
                 << "Help yourself to his one prized posession: a singular garbanzo bean.";
            return (0); //ends program
        }

        for (int i = 0; i < 4; i++)
        {
            cout << guesscode[i] << " "; //Outputs guessed code at end of loop
        }

        cout << "|| "
             << "Correct Location: " << correctlocation << " || " //Outputs number of correctnumber/correctlocation and correctnumber/incorrectlocation at end of loop
             << "Misplaced Location: " << incorrectlocation;
    }

    cout << endl
         << "Wow, it took you twelve tries and you didn't even manage to crack the code?" << endl; //If loop ends after 12 attempts, outputs message
    cout << "The correct code is: ";
    for (int i = 0; i < 4; i++)
    {
        cout << secretcode[i] << " "; //Outputs actual code
    }
    return (0); //ends program
}

void correctguesses(int secretcode_copy[], int guesscode_copy[], int &correctlocation, int &incorrectlocation) //Void function that takes both codes, and variables
                                                                                                               //holding correct number correct location/correct number incorrectlocation
                                                                                                               //via pass by reference
{
    for (int x = 0; x < 4; x++)
    { // CORRECT NUMBER, CORRECT LOCATION
        if (guesscode_copy[x] == secretcode_copy[x])
        {
            correctlocation++; //Adds 1 to correctlocation variable if values in both arrays are identical and in the same location
            guesscode_copy[x] = 'guess_pl';
            secretcode_copy[x] = 'secret_pl';
        }
    }

    for (int y = 0; y < 4; y++)
    {                               // CORRECT NUMBER, INCORRECT LOCATION
        for (int z = 0; z < 4; z++) //Nested loop to differentiate between locations
        {
            if (guesscode_copy[y] == secretcode_copy[z])
            {
                incorrectlocation++; //Adds 1 to correctlocation variable if values in both arrays are identical but not in the same location
                guesscode_copy[y] = '_guess_pl';
                secretcode_copy[z] = '_secret_pl';
            }
        }
    }
}