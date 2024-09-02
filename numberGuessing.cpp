#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout, std::cin, std::string;

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << '\t';
    }
    cout << '\n';
}

void play_game()
{
    // I added an array with the size of 101 to containe all the possible values
    int guesses[101];
    // and a guess count so i can determine the amount of guesses and make it the size of the array in the print_array() function
    int guess_count = 0;
    // the random variable will generate a random number using the rand() function
    //  and we can set a range from 0 to 100 by using the modular operator (%)
    int random = 1 + (rand() % 100);
    cout << "Guess a Number: ";
    // I created a (while loop) so it keeps running if the guess was wrong
    while (true)
    {
        int guess;
        cin >> guess;

        guesses[guess_count++] = guess;
        // here the if statement will check the input , if the input was right we will use the break; to break throw this loop
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
    cout << "your number of guesses: \n";
    print_array(guesses, guess_count);
}

int main()
{

    cout << "****************Welcome to the number guessing game****************\n";
    // I used the srand() function from the stdlib library because
    //  when you try to call the rand() function it will give you a random number
    //  but if you try to call it again it will give you the same number from before
    // so we use the srand() function because if you pass any random number to it as an argument , it will change the rand() number
    // but it will stick to this new random number too so we need to keep changing the passed number in the srand()
    // we can use the time() function from the ctime library, this function counts the seconds from the creation of c++ to this day
    srand(time(NULL));

    // I declared the variable choice so the (do while loop) can check the condition
    int choice;
    // I made a (do while loop ) so the game always run if want to play again
    do
    {
        // i put the input in the (do while loop ) so it always ask you when the game finish if you want to continue or not
        cout << "0. Quit" << std::endl
             << "1. Play Game\n";
        cin >> choice;

        // here I made a switch so it can has a case if you quit
        // and a case if you play the game
        // and a default if you chooses an invalid number
        switch (choice)
        {
        case 0:
            cout << "Thanks for nothing!\n";
            return 0;
        case 1:
            // here i made a function that has all the logic of the game
            play_game();
            break;
        default:
            cout << "invalid number!";
            break;
        }

    } while (choice != 0);

    return 0;
}