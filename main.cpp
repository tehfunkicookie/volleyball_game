#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

void display_game_rules();
int generate_guess_number();
bool didTouchCorrectly(int num);
bool didTeamFoul(std::string teamName, bool alreadyServed);

int main()
{
    display_game_rules();
    bool didTeam1Foul = true;
    bool didTeam2Foul = true;
    int counter = 0;

    while (didTeam1Foul && didTeam2Foul && counter < 3)
    {
        didTeam1Foul = didTeamFoul("team 1", false);
        if (didTeam1Foul)
        {
            didTeam2Foul = didTeamFoul("team 1", true);
        }
        counter++;
    }

    if (!didTeam1Foul)
    {
        std::cout << "team 1 fouled the ball" << std::endl;
    }
    else if (!didTeam2Foul)
    {
        std::cout << "team 2 fouled the ball" << std::endl;
    }
    else
    {
        std::cout << "nobody fouled. game stopped because counter was reached" << std::endl;
    }

    return 0;
}

void display_game_rules()
{
    std::cout << std::endl;
    std::cout << "Hello! Welcome to the C++ beach volleyball game. The purpose of this game is to practice your beach volleyball knowledge." << std::endl;
    std::cout << "The rules of the game are as follows: \n"
              << std::endl;
    std::cout << "1. 3 touches per side only. More than 3 touches will result in a dead ball and the opponent side winning a point." << std::endl;
    std::cout << "2. The ball cannot touch the ground. It will be considered a dead ball and the opponent side winning a point." << std::endl;
    std::cout << "3. Clean hand sets. If you cannot do a clean hand set, either bump set or you will be called on your hand sets if it's seen as a double contact or lift" << std::endl;
    std::cout << "4. Two players each side. One person can only touch the ball once unless the person going up to block touches the ball during a joust or block\n"
              << std::endl;
    std::cout << "Enjoy playing! Remember, play honestly and with good sportsmanship." << std::endl;
    std::cout << "Let the games begin!" << std::endl;
    std::cout << std::endl;
}

int generate_guess_number()
{
    srand(time(0));
    return rand();
}

bool didTouchCorrectly(int num)
{

    if (num < 0 || num > 4)
    {
        std::cout << "Invalid action for touching the ball." << std::endl;
        return false;
    }

    std::string actionSequence[5] = {"serve", "receive", "set", "spike", "dig"};

    long int user_input;
    long int guess_number = generate_guess_number();
    std::cout << "To " << actionSequence[num] << " the ball, you must type in the number " << guess_number << std::endl;

    std::cin >> user_input;

    if (user_input == guess_number)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool didTeamFoul(std::string teamName, bool alreadyServed)
{
    int i;
    if (alreadyServed == true)
    {
        i = 0;
    }
    else
    {
        i = 1;
    }

    std::cout << teamName + " has the ball!" << std::endl;
    for (i; i < 5; i++)
    {
        if (!didTouchCorrectly(i))
        {
            std::cout << "You lose!" << std::endl;
            return false;
        }
    }

    return true;
}