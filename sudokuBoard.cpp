#include <iostream>
#include <mutex>
#include <random>
#include <algorithm>
#include "sudokuBoard.h"
using namespace std;
#define boardLength 9

/*
sudoku board:
i   0  1  2  3  4  5  6  7  8 j 
0  {0, 0, 0, 0, 0, 0, 0, 0, 0,
1	0, 0, 0, 0, 0, 0, 0, 0, 0,
2	0, 0, 0, 0, 0, 0, 0, 0, 0,
3	0, 0, 0, 0, 0, 0, 0, 0, 0,
4	0, 0, 0, 0, 0, 0, 0, 0, 0,
5	0, 0, 0, 0, 0, 0, 0, 0, 0,
6	0, 0, 0, 0, 0, 0, 0, 0, 0,
7	0, 0, 0, 0, 0, 0, 0, 0, 0,
8	0, 0, 0, 0, 0, 0, 0, 0, 0}

where i is the coordinate of the row and j is the coordinate of the column.
A pair of i and j gives us the cooridnate of an element (e.g. [0][0] is the top left element)

*/
int Board::sudokuBoard[9][9] = {0};
mt19937 Board::gen(time(0));
uniform_int_distribution<> Board::distrib(1,9);

void Board::generateBoard() {
    for (int i = 0; i < boardLength; i++) {
        for (int j = 0; j < boardLength; j++) {
            int random; 
            int attempts = 0;  

            while (sudokuBoard[i][j] == 0 && attempts < 50) {
                random = generateRandom();

                if (!isInBox(i, j, random) && !isInRow(i, j, random) && !isInCol(i, j, random)) {
                    sudokuBoard[i][j] = random;
                }

                attempts++;
            }

            if (attempts >= 50) { //if we take too many attempts to fill out a cell, we assume that the board is unsolvable and reset until we make a solvable one.
                
                resetBoard();  
                generateBoard(); 
                return; 
            }
        }
    }
}


int Board::generateRandom(){

    return distrib(gen);
}
bool Board::isInRow(int row, int col, int value){
    
    for(int j = 0; j < boardLength; j++){
        if(value == sudokuBoard[row][j]){
            return true;
        }
    }
    return false;
}

bool Board::isInCol(int row, int col, int value){

    for(int i = 0; i < boardLength; i++){
        if (value == sudokuBoard[i][col]){
            return true;
        }
    }
    return false;
}

bool Board::isInBox(int row, int col, int value){

    int boxRow = (row/3) * 3;
    int boxCol = (col/3) * 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(sudokuBoard[boxRow + i][boxCol + j] == value){
                return true;
            }
        }
    }
    return false;
}

void Board::toString(){
    cout << "printing board: " << endl;
    for(int i = 0; i < boardLength; i++){
        for(int j = 0; j < boardLength; j++){
            cout << sudokuBoard[i][j] << " ";
        }
        cout << endl;
    }
}

void Board::resetBoard() {
    for (int i = 0; i < boardLength; i++) {
        for (int j = 0; j < boardLength; j++) {
            sudokuBoard[i][j] = 0;  
        }
    }
}

void Board::removeElements(){

    int numsToRemove = 40;
    while (numsToRemove > 0)
    {
        int i = generateRandom();
        int j = generateRandom();

        sudokuBoard[i][j] = 0;

        numsToRemove--;
    } 

}

void Board::clone(){
    
}