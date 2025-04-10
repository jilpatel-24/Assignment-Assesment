#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class RockPaperScissors 
{
	public:
    // Function to display the menu
   displayMenu() 
   {
        cout << "\nRock Paper Scissors Game\n";
        cout << "------------------------\n";
        cout << "1. Play Game\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
    }

    // Function to play the game
    playGame(int numRounds) 
	{
        // Seed the random number generator
        srand(time(0));

        int userWins = 0;
        int computerWins = 0;
		int round;
		
        for (round = 1; round <= numRounds;round++) 
		{
            cout << "\nRound " << round << ":\n";

            
            int userChoice;
            cout << "Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ";
            cin >> userChoice;

            
            while (userChoice < 1 || userChoice > 3) // Validate the user's choice
			{
                cout << "Invalid choice. Please enter a number between 1 and 3: ";
                cin >> userChoice;
            }

            
            int computerChoice = (rand() % 3) + 1; // For Generate a random choice for the computer

           
            if (userChoice == computerChoice)  // Determine the winner
			{
                cout << "It's a tie!\n";
            } 
			else if ((userChoice == 1 && computerChoice == 3) ||
                       (userChoice == 2 && computerChoice == 1) ||
                       (userChoice == 3 && computerChoice == 2)) 
			{
                cout << "You win, " << playerName << "!\n";
                userWins++;
            } 
			else 
			{
                cout << "Computer wins!\n";
                computerWins++;
            }

           
            cout << "You chose: ";  // Display the choices
            switch (userChoice) 
			{
                case 1:
                    cout << "Rock\n";
                    break;
                case 2:
                    cout << "Paper\n";
                    break;
                case 3:
                    cout << "Scissors\n";
                    break;
            }
            cout << "Computer chose: ";
            switch (computerChoice) 
			{
                case 1:
                    cout << "Rock\n";
                    break;
                case 2:
                    cout << "Paper\n";
                    break;
                case 3:
                    cout << "Scissors\n";
                    break;
            }
        }

        cout << "\nFinal Score:\n";
        cout << "You: " << userWins << "  Computer: " << computerWins << endl;
        if (userWins > computerWins) 
		{
            cout << "You won the game, " << playerName << "!\n";
        } else if (computerWins > userWins) {
            cout << "Computer won the game!\n";
        } else {
            cout << "The game ended in a tie!\n";
        }
    }
    string playerName; // Member variable to store the player's name
};

main() 
{
    RockPaperScissors game; // Create an object of the RockPaperScissors class

    cout << "Enter your name: ";
    cin >> game.playerName;

    int numRounds;
    cout << "Enter the number of rounds to play: ";
    cin >> numRounds;

    game.playGame(numRounds);  // Start the game
}

