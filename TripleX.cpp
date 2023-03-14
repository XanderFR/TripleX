#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    //Print welcome messages to the terminal
    std::cout << "You are an undercover spy infiltrating a level " << Difficulty;
    std::cout << " secure server room\nYou need to enter the correct codes to continue...\n";
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty); //Print the game intro messages

    //Declare 3 number codes
    const int CodeA = rand() % Difficulty + 1; //Random number between 1 and Difficulty
    const int CodeB = rand() % Difficulty + 1; //Random number between 1 and Difficulty
    const int CodeC = rand() % Difficulty + 1; //Random number between 1 and Difficulty

    const int CodeSum = CodeA + CodeB + CodeC; //Adds up the codes
    const int CodeProduct = CodeA * CodeB * CodeC; //Multiplies the codes

    //Prints sum and product values to the terminal
    std::cout << "\n";
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to give: " << CodeProduct << "\n";

    //Store player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC; //Adds the player guesses
    int GuessProduct = GuessA * GuessB * GuessC; //Multiplies the player guesses

    //Check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n\n";
        return true;
    }
    else {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***\n\n";
        return false;
    }
}

int main(){

    srand(time(NULL)); //Creates new random sequence based on the time of day
    
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty) { //Loop game until all levels are completed
        bool bLevelComplete = PlayGame(LevelDifficulty);
        //Fix endless loop issues
        std::cin.clear(); //Clears any errors in relation to input
        std::cin.ignore(); //Discards the buffer of bad input characters

        if (bLevelComplete) {
            ++LevelDifficulty; //increase LevelDifficulty by 1 then use it
        }
        
    }
    std::cout << "*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}