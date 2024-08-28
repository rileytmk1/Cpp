#include <iostream>

// No global variables
// No strings
// Use <iostream> not stdio


using namespace std;

int main()
{
  bool play = true;
  while(play == true){
    srand(time(NULL));
    int num = rand() % 100; // limit numbers to be between 0-100
    int guess; //varible for the user's guess
    int guesses = 0; // keep track of guesses
    char input; // user input to play again
    while (guess != num){ //continue forever until the user guesses correct
      cin >> guess;
      if (guess < num){
	cout << "Too low!" << endl;
      }
      else if (guess > num){
	cout << "Too high!" << endl;
      }
      guesses++; //update guesses after every guess
    }
    cout << "It took you" << " " << guesses << " " << "guesses!" << endl;
    cout << "Would you like to play again? (y or n)" << endl;
    cin >> input;
    if (input == 'n'){
      play = false;
    }
  }
  return 0;
  
}
