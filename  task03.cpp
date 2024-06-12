#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        cout << " | ";
      }
      cout << board[i][j] << " | ";
    }
    cout << endl;
  }
}

bool isWinner(char player) {
  // Check rows
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

bool isBoardFull() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int player = 1; 
  char mark;

  do {
 
    printBoard();

    
    if (player % 2 == 1) {
      mark = 'X';
      cout << "Player 1 (X), enter your move (1-9): ";
    } else {
      mark = 'O';
      cout << "Player 2 (O), enter your move (1-9): ";
    }

    int move;
    cin >> move;

   
    move--;

   
    while (board[move / 3][move % 3] != ' ') {
      cout << "Invalid move. Try again: ";
      cin >> move;
      move--;
    }

    board[move / 3][move % 3] = mark;

    
    if (isWinner(mark)) {
      printBoard();
      if (mark == 'X') {
        cout << "Player 1 (X) wins!" << endl;
      } else {
        cout << "Player 2 (O) wins!" << endl;
      }
      break;
    }

   
    if (isBoardFull()) {
      printBoard();
      cout << "It's a draw!" << endl;
      break;
    }

   
    player++;

  } while (true);

  return 0;
}
