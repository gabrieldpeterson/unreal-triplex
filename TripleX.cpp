#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Function Prototypes
void PrintAsciiArt();
void PrintIntroduction(int Difficulty);
bool PlayGame(int Difficulty, int MaxLevel);

int main()
{
    srand(time(NULL));
    PrintAsciiArt();

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;


    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        PrintIntroduction(LevelDifficulty);

        bool bLevelComplete = PlayGame(LevelDifficulty, MaxDifficulty);

        // Prevent an endless loop if invalid characters are entered
        cin.clear();
        cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    cout << "**************************************";
    cout << "\nCongratulations! You beat the game!\n";
    cout << "**************************************";

    return 0;
}

void PrintAsciiArt()
{
    string AsciiLine;
    ifstream AsciiFile("asciiart.txt");
    if (AsciiFile.is_open())
    {
        while (getline (AsciiFile, AsciiLine))
        {
            cout << AsciiLine << '\n';
        }
        AsciiFile.close();
    }
    else
    {
        cout << "Unable to open file\n";
    }
}

void PrintIntroduction(int Difficulty)
{
    cout << "\nYou are a secret agent breaking into a level " << Difficulty << " secure server room\n";
    cout << "You need to enter the correct codes to continue\n";
}

bool PlayGame(int Difficulty, int MaxLevel)
{
    // Change random range based on difficulty   
    int RandMod;
    switch (Difficulty)
    {
        case 1:
            RandMod = 5;
            break;
        case 2:
            RandMod = 7;
            break;
        case 3:
            RandMod = 9;
            break;
        case 4:
            RandMod = 12;
            break;
        case 5:
            RandMod = 15;
            break;
        default:
            RandMod = 15;
            break;
    }

    int CodeA = rand() % RandMod + 1;
    int CodeB = rand() % RandMod + 1;
    int CodeC = rand() % RandMod + 1;

    // Temp, gives answers. Delete later
    cout << CodeA << " " << CodeB << " " << CodeC;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    cout << "\n\n+ There are three numbers in the code";
    cout << "\n+ The codes add up to: " << CodeSum;
    cout << "\n+ The codes multiply to give: " << CodeProduct << endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "You win\n";
        Difficulty < MaxLevel ? cout << "The difficulty will increase\n" : cout << endl;
        return true;
    }
    else
    {
        cout << "You lose\n";
        cout << "You will retry your current level\n";
        return false;
    }
}