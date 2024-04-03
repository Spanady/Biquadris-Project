#ifndef CELL
#define CELL

#include "constants.h"

class Cell {
    blockType type;
    int row, col;

    public:
        Cell(int _row, int _col);
        ~Cell();

        blockType getType();
        bool isFilled();
        void setBlock(blockType _type);
        void setEmpty();
        int getRow();
        int getCol();
};

#endif
