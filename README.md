# tictactoe
C++ implementation of Tic-Tac-Toe

This is an implementation of the 3D Tic-Tac-Toe game, whereby there are many more win conditions than the standard 2D version.

A brief summary of the game be found [here](http://pi.math.cornell.edu/~mec/2003-2004/graphtheory/tictactoe/howtoplayttt.html) (scroll down to "Three-dimensional Tic-Tac-Toe").

Simply compile the cpp files using your C++ compiler of choice. 

Sample output:
```
Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer.
The board is numbered from 1 to 27 as per the following:
1 | 2 | 3      10 | 11 | 12      19 | 20 | 21
---------      ------------      ------------
4 | 5 | 6      13 | 14 | 15      22 | 23 | 24
---------      ------------      ------------
7 | 8 | 9      16 | 17 | 19      25 | 26 | 27
Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. 
Computer’s move is marked with O.
Start? (y/n):y
1 | 2 | 3      10 | 11 | 12      19 | 20 | 21
---------------------------------------
4 | 5 | 6      13 | 14 | 15      22 | 23 | 24      
---------------------------------------
7 | 8 | 9      16 | 17 | 18      25 | 26 | 27      
Type a cell number: 1
X | O | 3      10 | 11 | 12      19 | 20 | 21
---------------------------------------
4 | 5 | 6      13 | 14 | 15      22 | 23 | 24      
---------------------------------------
7 | 8 | 9      16 | 17 | 18      25 | 26 | 27      

Type a cell number: 5
X | O | 3      10 | 11 | 12      19 | 20 | 21
---------------------------------------
4 | X | 6      13 | 14 | 15      22 | 23 | 24      
---------------------------------------
7 | 8 | O      16 | 17 | 18      25 | 26 | 27      

Type a cell number: 4
X | O | 3      10 | 11 | 12      19 | 20 | 21
---------------------------------------
X | X | O      13 | 14 | 15      22 | 23 | 24      
---------------------------------------
7 | 8 | O      16 | 17 | 18      25 | 26 | 27      

Type a cell number: 7
X | O | 3      10 | 11 | 12      19 | 20 | 21
---------------------------------------
X | X | O      13 | 14 | 15      22 | 23 | 24      
---------------------------------------
X | 8 | O      16 | 17 | 18      25 | 26 | 27      
Player won.
```
