#include "cell.h"

Cell::Cell(int _row, int _col)
    : type{blockType::NONE}, row{_row}, col{_col} {}

Cell::~Cell() {}

blockType Cell::getType() {
    return type;
}

bool Cell::isFilled() {
    return type != blockType::NONE;
}

void Cell::setBlock(blockType _type) {
    this->type = _type;
    // this->observer->notify(type, row, col)
}

void Cell::setEmpty() {
    this->type = blockType::NONE;
    // this->observer->notify(type, row, col)
}

int Cell::getRow() { return row; }

int Cell::getCol() { return col; }
