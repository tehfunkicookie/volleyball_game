#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cstdlib>
#include <ctime>

void display_game_rules();
int generate_guess_number();
bool didTouchCorrectly(int num, bool isReceivingServe);
bool didTeamFoul(std::string teamName, bool alreadyServed, int play_counter);

int main()
{
    display_game_rules();
    bool didTeam1Foul = true;
    bool didTeam2Foul = true;
    int counter = 0;

    while (didTeam1Foul && didTeam2Foul && counter < 3)
    {

        if (counter == 0)
        {
            didTeam1Foul = didTeamFoul("team 1", false, counter);
        }
        else
        {
            didTeam1Foul = didTeamFoul("team 1", true, counter);
        }

        if (didTeam1Foul)
        {
            didTeam2Foul = didTeamFoul("team 2", true, counter);
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

bool didTouchCorrectly(int num, bool isReceivingServe)
{

    if (num < 0 || num > 4)
    {
        std::cout << "Invalid action for touching the ball." << std::endl;
        return false;
    }

    std::string firstTouch;
    if (isReceivingServe == true)
    {
        firstTouch = "receive";
    }
    else
    {
        firstTouch = "dig";
    }

    std::string actionSequence[4] = {"serve", firstTouch, "set", "spike"};
    std::string spikeOption[3] = {"line", "angle", "cut"};

    std::string static myAttack = "none";

    if (num == 3)
    {
        std::string userAttack;
        std::cout << "Which spot do you want to spike toward (line, angle, cut)?: ";
        std::cin >> myAttack;
        std::cout << "myAttack is currently: " << myAttack << std::endl;
    }

    long int user_input;

    // so i have to do different if statements for guessing the number..like if i'm digging a hit, I have to guess both the number and the direction it was hit
    // if its just receiving, setting, or spiking, then don't guess the direction
    if (num == 1 && myAttack != "none")
    {
        std::cout << "Which direction is the attack going to? (line, angle, cut): ";
        std::string user_guess;
        std::cin >> user_guess;
        std::cout << "User guess is: " << user_guess << " and the attack is: " << myAttack << std::endl;

        if (user_guess != myAttack)
        {
            return false;
        }

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
    else
    {
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
}

bool didTeamFoul(std::string teamName, bool alreadyServed, int play_counter)
{
    // team 1 always serves. so if alreadyServed == false or team1 is currently serving, then just do this:
    if (alreadyServed == false)
    {
        std::cout << teamName + " has the ball!" << std::endl;
        return didTouchCorrectly(0, false);
    }

    if (alreadyServed == true)
    {
        // if team is receiving a serve, then you'll have to do receive,set,spike
        // if a team is receiving a spike, it's dig,set,spike
        // since you only need to receive a serve once, then i need like a one time on off switch or flag
        if (play_counter == 0 && teamName == "team 2")
        {
            std::cout << teamName + " has the ball!" << std::endl;
            for (int i = 1; i < 4; i++)
            {
                if (!didTouchCorrectly(i, true))
                {
                    std::cout << "You lose!" << std::endl;
                    return false;
                }
            }
        }
        else
        { // you are digging the ball
            std::cout << teamName + " has the ball!" << std::endl;
            for (int i = 1; i < 4; i++)
            {
                if (!didTouchCorrectly(i, false))
                {
                    std::cout << "You lose!" << std::endl;
                    return false;
                }
            }
        }
    }

    return true;
}