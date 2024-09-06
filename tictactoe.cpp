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
  int xWins = 0;
  int oWins = 0;
  while(true){
    char input[3];
    char board[4][4] = {{' ', '1', '2', '3'}, {'a', ' ', ' ', ' '}, {'b', ' ', ' ', ' '}, {'c', ' ', ' ', ' '}};
    int player = 0;
    char playAgain;
    while(checkWin(board, 'X') == false && checkWin(board, 'O') == false && checkTie(board) == false){
      printBoard(board);
      cout << "Player" << " " << (player%2) + 1 << "," << " " << "enter your move." << endl;
      bool legal = false;
      while(legal == false){
	cin.get(input, 3);
	cin.get();
	if (board[(input[0]-'a') + 1][int(input[1]-'0')] != ' '){
	  cout << "Illegal move." << endl;
	}
	else{
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
    if (checkTie(board) == true && checkWin(board, 'X') == false && checkWin(board,'O') == false){
      cout << "It's a tie!" << endl;
      cout << "Leaderboard:" << endl;
      cout << "X: " << xWins << " " << "O: " << oWins << endl;
    }
    else{
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
    }
  }
  return 0;
}


