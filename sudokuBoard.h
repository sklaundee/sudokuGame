#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

class Board{
    static int sudokuBoard[9][9];
    public:
        void generateBoard();
        void setValues();
        int generateRandom();
        bool isInRow(int row, int col, int value);
        bool isInCol(int row, int col, int value);
        bool isInBox(int row, int col, int value);
        void toString();
};

#endif