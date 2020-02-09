#ifndef TICTACTOE_FUNCTIONS_H
#define TICTACTOE_FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <cstring>
#endif //TICTACTOE_FUNCTIONS_H
bool checkIfLegal (int cellNbre, char board[]);
bool checkWinner (char board[]);
void playerMove(char board[]);
void displayBoard (char board[]);
void greetAndInstruct();
void computerMove(char board[]);