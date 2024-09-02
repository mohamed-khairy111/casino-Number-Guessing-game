#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout, std::cin, std::string;

void play_game()
{
    int random = 1 + (rand() % 100);
    cout << random << '\n';
    cout << "Guess a Number: ";
    while (true)
    {
        int guess;
        cin >> guess;
        if (guess == random)
        {
            cout << "You Win!\n";
            break;
        }
        else if (guess < random)
        {
            cout << "Too low\n";
        }
        else
        {
            cout << "Too high\n";
        }
    }
}

int main()
{

    cout << "****************Welcome to the number guessing game****************\n";
    srand(time(NULL));
    int choice;

    do
    {
        cout << "0. Quit" << std::endl
             << "1. Play Game\n";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Thanks for nothing!\n";
            return 0;
        case 1:
            play_game();
            break;
        }

    } while (choice != 0);

    return 0;
}