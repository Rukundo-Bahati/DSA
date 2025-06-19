#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std; // Use standard namespace

// Function to display the word with guessed letters revealed
void displayWord(const string& word, const string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) != string::npos) {
            cout << letter;  // Show correctly guessed letter
        } else {
            cout << "_";     // Show underscore for unguessed letters
        }
    }
    cout << endl;
}

// Function to check if the player has guessed the word
bool isWordGuessed(const string& word, const string& guessedLetters) {
    for (char letter : word) {
        if (guessedLetters.find(letter) == string::npos) {
            return false;
        }
    }
    return true;
}

// Function to run a game session
bool playGame(const vector<string>& words) {
    string word = words[rand() % words.size()];  // Randomly select a word from category
    string guessedLetters = "";
    int remainingChances = 6;
    bool won = false;

    while (remainingChances > 0) {
        cout << "\nWord: ";
        displayWord(word, guessedLetters);

        char guess;
        cout << "Guess a letter (or type '0' to quit): ";
        cin >> guess;

        if (guess == '0') {
            return false; // Exit the game
        }

        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        guessedLetters += guess;

        if (word.find(guess) == string::npos) {
            remainingChances--;
            cout << "Incorrect! Remaining chances: " << remainingChances << endl;
        }

        if (isWordGuessed(word, guessedLetters)) {
            won = true;
            break;
        }
    }

    if (won) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Game over! The word was: " << word << endl;
    }

    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generator

    // Define categories with expanded word lists
    vector<string> animals = {"elephant", "giraffe", "kangaroo", "dolphin", "penguin", "cheetah", "hippopotamus", "ostrich", "rhinoceros", "lemur"};
    vector<string> teams = {"apr", "mukura", "patriots", "rayon", "warriors", "vision", "packers", "askigali", "gasogi", "giants"};
    vector<string> movies = {"inception", "gladiator", "titanic", "avatar", "joker", "interstellar", "matrix", "godfather", "avengers", "parasite"};
    vector<string> books = {"mobydick", "hamlet", "gatsby", "mockingbird", "1984", "ulysses", "frankenstein", "dracula", "hobbit", "beowulf"};
    vector<string> districts = {"gasabo", "kicukuro", "ngoma", "kayonza", "rwamagana", "nyabihu", "nyaruguru", "musanze", "rulindo", "rubavu"};

    bool playAgain = true;
    while (playAgain) {
        int categoryChoice;
  
        cout << "\t\t---------WORD GUESSING GAME---------" <<endl;     

        cout << "Choose a category:\n";
        cout << "1. Animals\n";
        cout << "2. Sports Teams\n";
        cout << "3. Movies\n";
        cout << "4. Books\n";
        cout << "5. Districts\n";
        cout << "Enter your choice (1-5): ";
        cin >> categoryChoice;

        // Select the word list based on category choice
        vector<string> chosenCategory;
        switch (categoryChoice) {
            case 1:
                chosenCategory = animals;
                break;
            case 2:
                chosenCategory = teams;
                break;
            case 3:
                chosenCategory = movies;
                break;
            case 4:
                chosenCategory = books;
                break;
            case 5:
                chosenCategory = districts;
                break;
            default:
                cout << "Invalid choice. Exiting...\n";
                return 0;
        }

        bool result = playGame(chosenCategory);
        if (!result) break; // Exit game if player chose to quit

        char response;
        cout << "\nDo you want to play again? (y/n): ";
        cin >> response;
        playAgain = (response == 'y' || response == 'Y');
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}
