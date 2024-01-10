#include<iostream>
#include <cstdlib>// for generating a random number.
#include <ctime>//for ensuring different random numbers each time
using namespace std;

int main()
{
 
    cout << "Welcome to the number gussing game!\n\n";
    cout<<"Here you will get 10 choices to guess the correct number\n\n";
    cout<<"SO LET's BEGIN !!!!!!\n\n";
    
    srand(time(0));
        int secret_num = 1 + (rand() % 100);
        int player_choice;
        
        
        int choicesLeft = 10;
            for (int i = 1; i <= 10; i++) 
			{
 
                cout << "\n\nEnter the number: ";
                cin >> player_choice;
 
                if (player_choice == secret_num) 
				{
                    cout << "Well played! You won, "<< player_choice<< " is the secret number" << endl;
                    cout << "\n Thanks for playing !!!!!"<< endl;
                    break;
                }
                else {
                    cout << "Nope, " << player_choice
                         << " is not the right number\n";
                    if (player_choice > secret_num) 
					{
                        cout << "The secret number is smaller than the number you have chosen"
                             << endl;
                    }
                    else {
                        cout << "The secret number is greater than the number you have chosen"
                             << endl;
                    }
                    choicesLeft--;
                    cout << choicesLeft << " choices left. ";
                    if (choicesLeft == 0) {
                        cout << "You couldn't find the secret number, it was "<< secret_num<< ", You lose!!\n\n";
                        cout << "Play the game again to win!!!\n\n";
                    }
                }
            }
        }


