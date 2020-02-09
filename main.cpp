#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstring>

using namespace std;

bool checkIfLegal (int cellNbre, char board[]) {
    return (cellNbre > 0 && cellNbre < 28 && board[cellNbre-1]!='x' && board[cellNbre-1]!='o');
}

void displaySpaces (int a, int b, char board[]) {
    for (int i = a; i <= b; i++) {
        switch (board[i - 1]) {
            case 'x':
                cout << 'x';
                break;
            case 'o':
                cout << 'o';
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
    for (int i = 0; i <=24; i+=3) {
        int player = 0;
        int cpu = 0;
        for (int j=i; j<i+3; j++) {
            switch (board[j]) {
                case 'x':
                    player++;
                    break;
                case 'o':
                    cpu++;
                    break;
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
    for (int i=0; i<=18; i+=9) {
        for (int j = i; j < i + 3; j++) {
            int player = 0;
            int cpu = 0;
            for (int k=j; k<=j+6; k+=3) {
                switch (board[k]) {
                    case 'x':
                        player++;
                        break;
                    case 'o':
                        cpu++;
                        break;
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
                case 'x':
                    player++;
                    break;
                case 'o':
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
                case 'x':
                    player++;
                    break;
                case 'o':
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

bool checkWinner (char board[]) {
    //Check each row
    switch (checkRow(board)) {
        case 'p':
            cout << "Player won.";
            return true;
        case 'c':
            cout << "Player lost.";
            return true;
    }
    //Check each column
    switch (checkColumn(board)) {
        case 'p':
            cout << "Player won.";
            return true;
        case 'c':
            cout << "Player lost.";
            return true;
    }
    //Check each diagonal
    switch (checkDiagonal(board)) {
        case 'p':
            cout << "Player won.";
            return true;
        case 'c':
            cout << "Player lost.";
            return true;
    }
    return false;
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

    int main() {
        //greetAndInstruct();
        char board[27];
        srand(time(NULL));
//        memset(board, ' ', 27);
//        cout << board << endl;
//        for (int i = 0; i < 27; i++) {
//            if (rand() % 2 == 0)
//                board[i] = 'x';
//            else
//                board[i] = 'o';
//        }
//        for (int i=0; i<=18; i+=9) {
//            for (int j=i; j<=i+8; j+=4) {
//                if (rand()%2==0)
//                    board[j]='x';
//                else
//                    board[j]='o';
//            }
//        }
        for (int i=2; i<=20; i+=9) {
            for (int j=i; j<=i+4; j+=2) {
                if (rand()%2==0)
                    board[j]='x';
                else
                    board[j]='o';
            }
        }
//        for (int i=0; i<=18; i+=9) {
//            for (int j = i; j < i + 3; j+=2) {
//                for (int k=j; k<=j+6; k+=3) {
//                    if(rand()%2==0)
//                        board[k]='x';
//                    else
//                        board[k]='o';
//                }
//            }
//        }
//        for (int i = 0; i <=24; i+=6) {
//            for (int j = i; j < i + 3; j++) {
//                if (rand() % 2 == 0)
//                    board[j] = 'x';
//                else
//                    board[j] = 'o';
//            }
//        }
        displayBoard(board);
        cout << endl;
        checkWinner(board);
        return 0;
    }