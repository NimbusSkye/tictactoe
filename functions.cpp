#include "functions.h"
using namespace std;

bool checkIfLegal (int cellNbre, char board[]) {
    return (cellNbre > 0 && cellNbre < 28 && board[cellNbre-1]!='X' && board[cellNbre-1]!='O');
}

void displaySpaces (int a, int b, char board[]) {
    //Display X or O, otherwise cell number
    for (int i = a; i <= b; i++) {
        switch (board[i - 1]) {
            case 'X':
                cout << 'X';
                break;
            case 'O':
                cout << 'O';
                break;
            default:
                cout << i;
        }
        if (i==b)
            break;
        cout << " | ";
    }
}

char checkRow (char board[]) {
    //Check rows like 1-2-3
    for (int i = 0; i <=24; i+=3) {
        int player = 0;
        int cpu = 0;
        for (int j=i; j<i+3; j++) {
            switch (board[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    return 'n';
}

char checkColumn (char board[]) {
    //Check columns like 1-4-7
    for (int i=0; i<=18; i+=9) {
        for (int j = i; j < i + 3; j++) {
            int player = 0;
            int cpu = 0;
            for (int k=j; k<=j+6; k+=3) {
                switch (board[k]) {
                    case 'X':
                        player++;
                        break;
                    case 'O':
                        cpu++;
                }
            }
            if (player == 3)
                return 'p';
            if (cpu == 3)
                return 'c';
        }
    }
    return 'n';
}

char checkDiagonal (char board[]) {
    //Check rightward diagonals, e.g. 1-5-9
    for (int i = 0; i <= 18; i += 9) {
        int player = 0;
        int cpu = 0;
        for (int j = i; j <= i + 8; j += 4) {
            switch (board[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    //Check leftward diagonals, e.g. 3-5-7
    for (int i=2; i<=20; i+=9) {
        int player = 0;
        int cpu = 0;
        for (int j = i; j <= i + 4; j += 2) {
            switch (board[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    return 'n';
}

char checkAdjacent (char board[]) {
    //Check for patterns like 1-9-19 (same cell on each board)
    for (int i = 0; i < 9; i++) {
        int player = 0;
        int cpu = 0;
        for (int j = i; j <= i + 18; j += 9) {
            switch (board[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player == 3)
            return 'p';
        if (cpu == 3)
            return 'c';
    }
    return 'n';
}

char checkSkewLines (char board[]) {
    //Check for patterns like 1-11-21 (row across all 3 boards)
    for (int i=0; i<=6; i+=3) {
        int player=0;
        int cpu=0;
        for (int j=i; j<=i+20; j+=10) {
            switch (board[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    //Check for patterns like 1-13-25 (column across all 3 boards)
    for (int i=0; i<3; i++) {
        int player=0;
        int cpu=0;
        for (int j=i; j<=i+24; j+=12) {
            switch (board[j]) {
                case 'X':
                    player++;
                    break;
                case 'O':
                    cpu++;
            }
        }
        if (player==3)
            return 'p';
        if (cpu==3)
            return 'c';
    }
    //Check for patterns 1-14-27 and 3-14-25
    if (board[0]=='X' && board[13]=='X' && board[26]=='X')
        return 'p';
    if (board[0]=='O' && board[13]=='O' && board[26]=='O')
        return 'c';
    if (board[2]=='X' && board[13]=='X' && board[24]=='X')
        return 'p';
    if (board[2]=='O' && board[13]=='O' && board[24]=='O')
        return 'c';
    return 'n';
}

bool checkWinner (char board[]) {
    //Check each row
    switch (checkRow(board)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each column
    switch (checkColumn(board)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each diagonal
    switch (checkDiagonal(board)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each adjacent pattern e.g. 1-10-19
    switch (checkAdjacent(board)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    //Check each skew line e.g. 1-11-21, 1-13-25, 1-14-27, 3-14-25
    switch (checkSkewLines(board)) {
        case 'p':
            return true;
        case 'c':
            return true;
    }
    return false;
}

void playerMove(char board[]) {
    int m=1;
    while(true) {
        cout << "Type a cell number: ";
        cin >> m;
        if (checkIfLegal(m, board))
            break;
        cout << "Illegal move." << endl;
    }
        board[m - 1] = 'X';
}

void displayBoard (char board[]) {
    displaySpaces(1, 3, board);
    cout << "      ";
    displaySpaces(10, 12, board);
    cout << "      ";
    displaySpaces(19, 21, board);
    cout << endl << "---------------------------------------" << endl;
    displaySpaces(4, 6, board);
    cout << "      ";
    displaySpaces(13, 15, board);
    cout << "      ";
    displaySpaces(22, 24, board);
    cout << "      ";
    cout << endl << "---------------------------------------" << endl;
    displaySpaces(7, 9, board);
    cout << "      ";
    displaySpaces(16, 18, board);
    cout << "      ";
    displaySpaces(25, 27, board);
    cout << "      ";
}


void greetAndInstruct() {
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
    cout << "The board is numbered from 1 to 27 as per the following:" << endl;
    cout << "1 | 2 | 3      10 | 11 | 12      19 | 20 | 21" << endl;
    cout << "---------      ------------      ------------" << endl;
    cout << "4 | 5 | 6      13 | 14 | 15      22 | 23 | 24" << endl;
    cout << "---------      ------------      ------------" << endl;
    cout << "7 | 8 | 9      16 | 17 | 19      25 | 26 | 27" << endl;
    cout
            << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O."
            << endl;
    cout << "Start? (y/n):";
    char ans;
    cin >> ans;
    char board[27];
    if (ans == 'y')
        displayBoard(board);
    else
        exit(0);
}

void computerMove(char board[]) {
    char test[27];
    for (int i = 0; i < 27; i++) {
        //Protect original board by copying it into another array
        copy(board, board+27, test);
        //Check if each move is legal using the test array, then commit if that cell is a win condition
        if (checkIfLegal(i+1, test)) {
            //Check for computer's win condition
            test[i]='O';
            if (checkWinner(test)) {
                board[i] = 'O';
                return;
            }
            //Check for player's win condition
            test[i]='X';
            if (checkWinner(test)) {
                board[i]='O';
                return;
            }
        }
    }
    //If no cell is a win condition, make a random move
    for (int i=0; i<27; i++) {
        if (checkIfLegal(i+1, board)) {
            board[i] = 'O';
            return;
        }
    }
}

