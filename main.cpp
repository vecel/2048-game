#include<iostream>
#include<conio.h>
#include<ctime>
#include<Board.h>

void makeMove(Board&);

int main(){
    srand(time(NULL));

    Board board;
    board.display();

    /** -- Game Loop -- */
    while(true){
        makeMove(board);
        board.addBasicTile();
        system("cls");
        board.display();
    }


    /**
    @TODO ? create a Game class ?
        check if game is already won or lost
    */
}

void makeMove(Board& bd){
    int a;
    bool moved = false;
    while(!moved){
        a = getch();
        switch(a){
            case Board::KEY_UP:
            case Board::KEY_DOWN:
            case Board::KEY_LEFT:
            case Board::KEY_RIGHT:{
                Board::Arrow arrow = static_cast<Board::Arrow>(a);
                bd.moveTiles(arrow);
                moved = true;
                break;
            }
        }
    }
}
