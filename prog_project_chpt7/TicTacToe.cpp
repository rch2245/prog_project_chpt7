// ===========================================
// Tic-Tac-Toe Game - Program Analysis & Design
// ===========================================

// Types of Input:
// - Player 1 and Player 2 enter row and column values (1–3) for moves.

// Program Output:
// - Display of the 3x3 game board.
// - Player prompts for turns.
// - Result declaration (Player 1 wins, Player 2 wins, or Tie).

// Formula / Logic:
// - Win: 3 of the same token in a row, column, or diagonal.
// - Tie: All cells filled without a winner.

// Algorithm / Tasks:
// 1. Initialize 3x3 board to '*'
// 2. Display board
// 3. While game state is "PLAY":
//    a. Prompt Player 1, get input, place 'X', check state, display board
//    b. If not done, prompt Player 2, get input, place 'O', check state
// 4. Display result message

// Hierarchy Chart:
// runTicTacToe()
// - initializeBoard()
// - displayBoard()
// - placeToken()
//   - getLocation()
// - getBoardState()
//   - checkForWinner()
//   - boardHasSpace()

// Pseudocode:
// initializeBoard(board)
// displayBoard(board)
// while state == PLAY:
//     Player 1's Turn
//     placeToken(X)
//     displayBoard()
//     checkBoardState(X)
//     if win/tie break
//
//     Player 2's Turn
//     placeToken(O)
//     displayBoard()
//     checkBoardState(O)

// if X_WIN: "Player 1 wins"
// else if O_WIN: "Player 2 wins"
// else: "It's a tie"

// Example Output:
// Player 1's Turn (X):
// Enter the row (1-3): 1
// Enter the column (1-3): 1

//   1 2 3
// 1 X * *
// 2 * * *
// 3 * * *
//
// Player 2's Turn (O):
// Enter the row (1-3): 2
// Enter the column (1-3): 2

//   1 2 3
// 1 X * *
// 2 * O *
// 3 * * *

#include "pch.h"
#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '*';
}

void displayBoard(const char board[3][3]) {
    cout << "\n  1 2 3\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) cout << board[i][j] << " ";
        cout << endl;
    }
}

void getLocation(int& row, int& col, const char board[3][3]) {
    do {
        cout << "Enter the row (1-3): ";
        cin >> row;
        cout << "Enter the column (1-3): ";
        cin >> col;

        // Convert to 0-based indexing
        row--;
        col--;

        if (row < 0 || row >= 3 || col < 0 || col >= 3)
            cout << "Invalid input. Row and column must be between 1 and 3.\n";
        else if (board[row][col] != '*')
            cout << "That cell is already occupied. Choose a different spot.\n";

    } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '*');
}


bool checkForWinner(char token, const char board[3][3]) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == token && board[i][1] == token && board[i][2] == token) ||
            (board[0][i] == token && board[1][i] == token && board[2][i] == token))
            return true;
    return (board[0][0] == token && board[1][1] == token && board[2][2] == token) ||
           (board[0][2] == token && board[1][1] == token && board[2][0] == token);
}

bool boardHasSpace(const char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '*') return true;
    return false;
}

string getBoardState(char token, const char board[3][3]) {
    if (checkForWinner(token, board)) return token == 'X' ? "X_WIN" : "O_WIN";
    return boardHasSpace(board) ? "PLAY" : "TIE";
}

void placeToken(char token, char board[3][3]) {
    int row, col;
    getLocation(row, col, board);
    board[row][col] = token;
}

void runTicTacToe() {
    char board[3][3];
    string boardState = "PLAY";
    char p1 = 'X', p2 = 'O';

    initializeBoard(board);
    displayBoard(board);

    while (boardState == "PLAY") {
        cout << "\nPlayer 1's Turn (X):\n";
        placeToken(p1, board);
        displayBoard(board);
        boardState = getBoardState(p1, board);
        if (boardState != "PLAY") break;

        cout << "\nPlayer 2's Turn (O):\n";
        placeToken(p2, board);
        displayBoard(board);
        boardState = getBoardState(p2, board);
    }

    if (boardState == "X_WIN")
        cout << "Player 1 wins!\n";
    else if (boardState == "O_WIN")
        cout << "Player 2 wins!\n";
    else
        cout << "It's a tie!\n";
}
