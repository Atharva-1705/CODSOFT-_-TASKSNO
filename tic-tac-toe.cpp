#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
    for (int i = 0; i < 3; i++)
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove() {
    int choice;
    cout << "Player " << currentPlayer << ", enter your move (1-9): ";
    cin >> choice;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == choice + '0') {
                board[i][j] = currentPlayer;
                return;
            }

    cout << "Invalid move! Try again.\n";
    makeMove();
}

int main() {
    bool gameOver = false;
    while (!gameOver) {
        displayBoard();
        makeMove();

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        } else if (checkDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            switchPlayer();
        }
    }
    return 0;
}
