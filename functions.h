#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>

#ifndef TICTACTOE_FUNCTIONS_H
#define TICTACTOE_FUNCTIONS_H
bool checkIfLegal (int cellNbre, char board[]);
bool checkWinner (char board[]);
char whoWins (char board[]);
void playerMove(char board[]);
void displayBoard (char board[]);
void greetAndInstruct();
void computerMove(char board[]);
#endif //TICTACTOE_FUNCTIONS_H
