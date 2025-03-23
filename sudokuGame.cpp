#include <iostream>
#include "sudokuBoard.h"
#define boardLength 9

using namespace std;

int main(){
    cout << "starting game" << endl;
    Board gameBoard;
    gameBoard.generateBoard(); 
    gameBoard.toString();    

    return 0;
}