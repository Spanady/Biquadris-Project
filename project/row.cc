#include "row.h"

Row::Row(int _row) 
    : filledCells{0}, row{_row} {
    for (int i = 0; i < rowData.size(); ++i) {
        rowData[i] = std::make_unique<Cell>(_row, i);
    }
}

Row::~Row() {}

bool Row::isRowFilled() {
    return filledCells == 11;
}

bool Row::isCellFilled(const int col) {
    return rowData[col]->isFilled(); 
}

bool Row::setCellType(const int col, blockType type) {
    if (col < 0 || col >= rowData.size()) {
        return false;
    }
    rowData[col]->setBlock(type);
    if (type != blockType::NONE) {
        filledCells++;
    }
    return true;
}

void Row::clear() {
    filledCells = 0;
    for (auto &cell: rowData) {
        cell->setEmpty();
    }
}
