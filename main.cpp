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
            cout << endl << "Player won.";
            break;
        }
        computerMove(board);
        if (checkWinner(board)) {
            displayBoard(board);
            cout << endl << "Player lost.";
            break;
        }
        displayBoard(board);
        cout << endl << endl;
    }
    return 0;
}