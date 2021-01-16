#include "Board.h"

Board::Board()
{
    addBasicTile();
    addBasicTile();
    //ctor
}

Board::~Board()
{
    //dtor
}

void Board::display(){
    for(int i = 0; i < SIZE; ++i){
        for(int k = 0; k < SIZE; ++k){
            std::cout << std::setw(4) << board[i][k].getValue();
        }
        std::cout << '\n';
    }
}

void Board::moveTiles(Arrow arrow){
    switch(arrow){
        case KEY_UP:
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_LEFT:
            moveLeft();
            break;
        case KEY_RIGHT:
            moveRight();
            break;
    }
}

void Board::addBasicTile(){
    if(isEmptyTile()){
        bool added = false;
        int x, y;
        while(!added){
            x = rand() % SIZE;
            y = rand() % SIZE;
            if(!board[x][y].getValue()){
                board[x][y].setValue(BASIC_VALUE);
                added = true;
            }
        }
    } else {
        std::cout << "There is no empty Tile\n";
        getch(); // gets '\n' character
    }
}

bool Board::isEmptyTile(){
    for(int i = 0; i < SIZE; ++i){
        for(int k = 0; k < SIZE; ++k){
            if(!board[i][k].getValue()) return true;
        }
    }
    return false;
}

void Board::moveUp(){
    for(int i = 0; i < SIZE; ++i){
        int val = -1;
        int pos = 0;
        for(int k = 0; k < SIZE; ++k){
            if(board[k][i].getValue()){
                if(val == -1){
                    val = board[k][i].getValue();
                    board[k][i].setValue(0);
                    board[pos][i].setValue(val);
                } else if(val == board[k][i].getValue()){
                    board[pos][i].doubleUp();
                    pos++;
                    val = -1;
                    board[k][i].setValue(0);
                } else {
                    val = board[k][i].getValue();
                    pos++;
                    board[k][i].setValue(0);
                    board[pos][i].setValue(val);
                }
            }
        }
    }
}

void Board::moveDown(){
    for(int i = 0; i < SIZE; ++i){
        int val = -1;
        int pos = SIZE - 1;
        for(int k = SIZE - 1; k >= 0; --k){
            if(board[k][i].getValue()){
                if(val == -1){
                    val = board[k][i].getValue();
                    board[k][i].setValue(0);
                    board[pos][i].setValue(val);
                } else if(val == board[k][i].getValue()){
                    board[pos][i].doubleUp();
                    pos--;
                    val = -1;
                    board[k][i].setValue(0);
                } else {
                    val = board[k][i].getValue();
                    pos--;
                    board[k][i].setValue(0);
                    board[pos][i].setValue(val);
                }
            }
        }
    }
}

void Board::moveLeft(){
    for(int i = 0; i < SIZE; ++i){
        int val = -1;
        int pos = 0;
        for(int k = 0; k < SIZE; ++k){
            if(board[i][k].getValue()){
                if(val == -1){
                    val = board[i][k].getValue();
                    board[i][k].setValue(0);
                    board[i][pos].setValue(val);
                } else if(val == board[i][k].getValue()){
                    board[i][pos].doubleUp();
                    pos++;
                    val = -1;
                    board[i][k].setValue(0);
                } else {
                    val = board[i][k].getValue();
                    pos++;
                    board[i][k].setValue(0);
                    board[i][pos].setValue(val);
                }
            }
        }
    }
}

void Board::moveRight(){
    for(int i = 0; i < SIZE; ++i){
        int val = -1;
        int pos = SIZE - 1;
        for(int k = SIZE - 1; k >= 0; --k){
            if(board[i][k].getValue()){
                if(val == -1){
                    val = board[i][k].getValue();
                    board[i][k].setValue(0);
                    board[i][pos].setValue(val);
                } else if(val == board[i][k].getValue()){
                    board[i][pos].doubleUp();
                    pos--;
                    val = -1;
                    board[i][k].setValue(0);
                } else {
                    val = board[i][k].getValue();
                    pos--;
                    board[i][k].setValue(0);
                    board[i][pos].setValue(val);
                }
            }
        }
    }
}
