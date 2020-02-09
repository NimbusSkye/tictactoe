#include "functions.h"
using namespace std;

int main() {
    char board[27];
    srand(time(NULL));
    greetAndInstruct();
    cout << endl;
    while (true) {
        playerMove(board);
        if (checkWinner(board)) {
            displayBoard(board);
            cout << endl;
            break;
        }
        computerMove(board);
        if (checkWinner(board)) {
            displayBoard(board);
            cout << endl;
            break;
        }
        displayBoard(board);
        cout << endl;
    }
    switch (whoWins(board)) {
        case 'p':
            cout << "Player won.";
            break;
        default:
            cout << "Player lost.";
    }
    return 0;
}