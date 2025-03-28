#include <iostream>
#include "sudokuBoard.h"
#define boardLength 9

using namespace std;

int main(){
    cout << "starting game" << endl;
    Board gameBoard;
    gameBoard.generateBoard(); 
    gameBoard.toString();    

    Board answer = gameBoard;
    cout << "answer board" << endl;
    answer.toString();

    cout << "removing elements" << endl;
    gameBoard.removeElements();

    gameBoard.toString();
    answer.toString();
    

    return 0;
}