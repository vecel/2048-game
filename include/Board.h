#include<Tile.h>
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<conio.h>

#ifndef BOARD_H
#define BOARD_H


class Board
{
    public:
        enum Arrow{ KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77 };

        static const int SIZE = 4;
        static const int BASIC_VALUE = 2;

        Board();
        virtual ~Board();
        void display();  // displays the board
        void moveTiles(Arrow); // moves Tiles in the correct direction
        void addBasicTile(); // adds a Tile with value 2 at random empty position

    protected:

    private:
        Tile board[SIZE][SIZE];

        bool isEmptyTile(); // returns true if there is any Tile with value 0
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

#endif // BOARD_H
