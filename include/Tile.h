#ifndef TILE_H
#define TILE_H


class Tile
{
    public:
        Tile();
        virtual ~Tile();
        int getValue();
        void setValue(int);
        void doubleUp(); // doubles up a value

    protected:

    private:
        int value;
};

#endif // TILE_H
