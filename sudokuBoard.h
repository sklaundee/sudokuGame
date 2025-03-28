#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H
#include <random>


class Board{
    static int sudokuBoard[9][9];
    static std::mt19937 gen;
    static std::uniform_int_distribution<> distrib;    

    public:
        void generateBoard();
        void setValues();
        int generateRandom();
        bool isInRow(int row, int col, int value);
        bool isInCol(int row, int col, int value);
        bool isInBox(int row, int col, int value);
        void toString();
        void resetBoard();
        void removeElements();
        void clone();
};

#endif