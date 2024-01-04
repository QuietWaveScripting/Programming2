#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int MAX_GUESSES = 10;

void clean_screen();

bool is_word_already_guessed(string secret, string guessed);

void print_game_status(string secret, string guessed);

int main() {
    string secret_word = "";
    cout << "Give a word to be guessed: ";
    getline(cin, secret_word);

    clean_screen();

    string guessed_letters = "";
    int guesses_used = 0;

    while (not is_word_already_guessed(secret_word, guessed_letters) and guesses_used < MAX_GUESSES) {
        cout << endl << "Game status: ";
        print_game_status(secret_word, guessed_letters);

        if (guessed_letters.size() > 0) {
            cout << "You have used " << guesses_used
                 << " guesses!"
                 << endl
                 << "You have guessed letters: " << guessed_letters
                 << endl;
        }

        string guess = "";
        cout << "Guess a letter: ";
        getline(cin, guess);

        if (guess.size() != 1) {
            cout << "You failed: give exactly one letter!" << endl;
            continue;

        } else if (guessed_letters.find(guess) != string::npos) {
            cout << "You failed: you had already guessed the letter " << guess << "!" << endl;
            continue;
        }

        guessed_letters += guess;

        if (secret_word.find(guess) == string::npos) {
            cout << "Guessed letter does not include the word!" << endl;
        }

        ++guesses_used;
    }

    if (not is_word_already_guessed(secret_word, guessed_letters)) {
        cout << endl << "Guesses expired!" << endl;

    } else {
        cout << endl << "Right guess. You used " << guesses_used
             << " guesses!"
             << endl;
    }

    return 0;
}

void clean_screen() {
    for (int i = 0; i < 100; ++i) {
        cout << endl;
    }
}

bool is_word_already_guessed(string secret, string guessed) {
    for (string::size_type index = 0; index < secret.size(); ++index) {
        char secret_char = tolower(secret.at(index));
        if (guessed.find(secret_char) == string::npos) {
            return false;
        }
    }
    return true;
}

void print_game_status(string secret, string guessed) {
    for (char secret_char: secret) {
        if (guessed.find(secret_char) == string::npos) {
            cout << "_";
        } else {
            cout << secret_char;
        }
    }
    cout << endl;
}
