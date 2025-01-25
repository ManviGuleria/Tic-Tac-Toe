#include <iostream>
#include <string>
using namespace std;

void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char currentPlayer);
void getPlayerMove(char board[3][3], char currentPlayer, string playerName);

int main() {
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    string player1, player2;
    cout << "\t\t** TIC-TAC-TOE **\n\n";
    cout << "Enter Player 1 name: ";
    getline(cin, player1);
    cout << "Enter Player 2 name: ";
    getline(cin, player2);

    char currentPlayer = 'X';
    string currentPlayerName = player1;

    for (int i = 0; i < 9; i++) {
        displayBoard(board);
        getPlayerMove(board, currentPlayer, currentPlayerName);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << currentPlayerName << " wins!\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        currentPlayerName = (currentPlayerName == player1) ? player2 : player1;
    }

    displayBoard(board);
    cout << "It's a draw!\n";
    return 0;
}

void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool checkWin(char board[3][3], char currentPlayer) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

void getPlayerMove(char board[3][3], char currentPlayer, string playerName) {
    int move;
    cout << playerName << "'s turn (" << currentPlayer << "). Enter your move: ";
    while (true) {
        cin >> move;
        if (move >= 1 && move <= 9) {
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                board[row][col] = currentPlayer;
                break;
            } else {
                cout << "Position already taken. Try again: ";
            }
        } else {
            cout << "Invalid move. Enter a number between 1 and 9: ";
        }
    }
}
