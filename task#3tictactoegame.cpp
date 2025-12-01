#include <iostream>
using namespace std;

char board[3][3];
char player1, player2;

// Reset board to empty spaces
void resetBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Print the board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Count how many spaces left
int checkFreeSpace() {
    int freeSpace = 9;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != ' ')
                freeSpace--;
    return freeSpace;
}

// Take player's move
void playerMove(char c) {
    int x, y;
    while (true) {
        cout << "Player " << c << ", enter row (1-3): ";
        cin >> x;
        cout << "Player " << c << ", enter column (1-3): ";
        cin >> y;

        x--; y--;

        // Check valid range
        if (x < 0 || x > 2 || y < 0 || y > 2) {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Check cell empty
        if (board[x][y] != ' ') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[x][y] = c;
        break;
    }
}

// Check all win conditions
char checkWinner() {

    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return board[i][0];

    // Columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] != ' ' &&
            board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return board[0][i];

    // Diagonal 1
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    // Diagonal 2
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return ' '; // no winner yet
}

// Print result
void printWinner(char w) {
    if (w == player1)
        cout << "PLAYER ONE WINS!\n";
    else if (w == player2)
        cout << "PLAYER TWO WINS!\n";
    else
        cout << "IT'S A TIE!\n";
}

int main() {

start:
    char winner = ' ';
    char response;

    cout << "PLAYER ONE symbol: ";
    cin >> player1;

    do {
        cout << "PLAYER TWO symbol: ";
        cin >> player2;
    } while (player1 == player2);

    resetBoard();

    while (winner == ' ' && checkFreeSpace() > 0) {

        printBoard();
        playerMove(player1);

        winner = checkWinner();
        if (winner != ' ' || checkFreeSpace() == 0) break;

        printBoard();
        playerMove(player2);

        winner = checkWinner();
    }

    printBoard();
    printWinner(winner);

    cout << "Play again? (Y/N): ";
    cin >> response;

    if (response == 'Y' || response == 'y')
        goto start;

    cout << "Thanks for playing!\n";
    return 0;
}
