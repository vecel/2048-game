#include "Tile.h"

Tile::Tile()
{
    //ctor
    value = 0;
}

Tile::~Tile()
{
    //dtor
}

int Tile::getValue(){
    return value;
}

void Tile::setValue(int v){
    value = v;
}

void Tile::doubleUp(){
    value *= 2;
}
