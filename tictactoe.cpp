#include <iostream>
#include <cstring>

using namespace std;

void printBoard(char board[4][4])
{
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}

bool checkWin(char board[4][4], char player) //check horizontals, verticals, and diagonals for wins.
{
  if (board[1][1] == player && board[1][2] == player && board[1][3] == player){
    return true;
  }
  if (board[2][1] == player && board[2][2] == player && board[2][3] == player){
    return true;
  }
  if (board[3][1] == player && board[3][2] == player && board[3][3] == player){
    return true;
  }
  if (board[1][1] == player && board[2][1] == player && board[3][1] == player){
    return true;
  }
  if (board[1][2] == player && board[2][2] == player && board[3][2] == player){
    return true;
  }
  if (board[1][3] == player && board[2][3] == player && board[3][3] == player){
    return true;
  }
  if (board[1][1] == player && board[2][2] == player && board[3][3] == player){
    return true;
  }
  if (board[1][3] == player && board[2][2] == player && board[3][1] == player){
    return true;
  }
  else{
    return false;
  }
}

bool checkTie(char board[4][4]) //if all spaces are filled and no win has been made, its a tie.
{
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      if (i == 0 && j == 0){
	continue;
      }
      if (board[i][j] == ' '){
	return false;
      }
    }
  }
  return true;
}

int main()
{
  //hold wins
  int xWins = 0;
  int oWins = 0;
  bool playAgain = true;
  while(playAgain){
    char input[5];
    // represent board with a 2d array
    char board[4][4] = {{' ', '1', '2', '3'}, {'a', ' ', ' ', ' '}, {'b', ' ', ' ', ' '}, {'c', ' ', ' ', ' '}};
    //keep track of player
    int player = 0;
    char play[5];
    while(checkWin(board, 'X') == false && checkWin(board, 'O') == false && checkTie(board) == false){
      printBoard(board);
      cout << "Player" << " " << (player%2) + 1 << "," << " " << "enter your move. (enter quit to stop playing)" << endl;
      bool legal = false;
      while(legal == false){
	cin.get(input, 5);
	cin.get();
	if (strcmp(input, "quit") == 0){ //end program when quit
	  exit(0);
	}
	else if (board[(input[0]-'a') + 1][int(input[1]-'0')] != ' '){ //use coordinates of the grid to locate the spot and check if it is empty
	  cout << "Illegal move." << endl;
	}
	else{ //if valid move figure out what player we are on and place an X or O depending on player.
	  if (player % 2 == 0){
	    board[(input[0]-'a') + 1][int(input[1]-'0')] = 'X';
	  }
	  else{
	    board[(input[0]-'a') + 1][int(input[1]-'0')] = 'O';
	  }
	  legal = true;
	}
      }
      player++;
    }
    if (checkTie(board) == true && checkWin(board, 'X') == false && checkWin(board,'O') == false){ //check for ties
      printBoard(board);
      cout << "It's a tie!" << endl;
      cout << "Leaderboard:" << endl;
      cout << "X: " << xWins << " " << "O: " << oWins << endl;
    }
    else{ //check for wins
      if ((player % 2) -1 == 0){
	xWins++;
      }
      else{
	oWins++;
      }
      printBoard(board);
      cout << "Player" << " " << (player % 2) << " " << "wins!" << endl;
      cout << "Leaderboard:" << endl;
      cout << "X: " << xWins << " " << "O: " << oWins << endl;
      cout << "Play Again?" << endl;
      cin.get(play, 4);
      cin.get();
      if (strcmp(play, "no") == 0){
	playAgain = false;
      }
    }
    
  }
  return 0;
}


