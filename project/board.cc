#include "board.h"

Board::Board() : colHeights{BOARD_WIDTH, 0} {
    for (int i = 0; i < rows.size(); ++i) {
        rows[i] = std::make_shared<Row>(i);
    }
}

Board::~Board() {}

void Board::reset() {
    for (auto &row : rows) {
        row->clear();
    }
    for (auto &height : colHeights) {
        height = 0;
    }
}

void Board::clearRow(const int row) {

    // Clear the cells in the row
    rows[row]->clear();

     // Transfer ownership of row
    std::shared_ptr<Row> clearedRow = std::move(rows[row]);

    // Delete depracated pointer
    rows.erase(rows.begin() + row);

    // Place row at the top
    rows.emplace_back(clearedRow);

    // Reduce the height of each column by 1
    for (auto &height : colHeights) {
        --height;
    }
}

int Board::getHeight(const int col) {
    if (col > BOARD_WIDTH || col < 0) {
        return -1;
    }
    return colHeights[col];
}

bool Board::getisLost() {
    for (auto &height : colHeights) {
        if (height > BOARD_HEIGHT) return true;
    }
    return false;
}

bool Board::canDrop(const std::vector<int> &blockRows, const std::vector<int> &blockCols) {

    // Iterate through each block location and check if it is already filled
    // Or if the block is attempting to be placed underneath an existing block
    // Or if a row/column is not in valid range
    int row, col;

    for (int i = 0; i < blockRows.size(); ++i) {
        row = blockRows[i];
        col = blockCols[i];
        if (row < 0 || row > BOARD_HEIGHT) return false;
        if (col < 0 || col > BOARD_WIDTH) return false;
        if (rows[row]->isCellFilled(col)) return false;
        if (colHeights[col] >= row) return false;
    }

    return true;
}

bool Board::addBlock(const std::vector<std::shared_ptr<Cell>> blockData) {
    int blockSize = blockData.size();
    if (blockSize == 0) return true;    // Auto success if no Cells in block (for future-proofing)

    blockType type = blockData[0]->getType();
    std::vector<int> blockRows{blockSize}, blockCols{blockSize}; 

    for (int i = 0; i < blockSize; ++i) {
        blockRows[i] = blockData[i]->getRow();
        blockCols[i] = blockData[i]->getCol();
    }

    return _addBlock(blockRows, blockCols, type);
}

// TODO need to decide if win/loss check occurs first, or if row clearing occurs first
bool Board::_addBlock(const std::vector<int> &blockRows, const std::vector<int> &blockCols, const blockType type) {
    if (type == blockType::NONE) return false;
    if (!canDrop(blockRows, blockCols)) return false;

    // Insert each block and update column height accordingly
    for (int i = 0; i < blockRows.size(); ++i) {
        rows[blockRows[i]]->setCellType(blockCols[i], type);
        if (blockRows[i] > colHeights[blockCols[i]]) colHeights[blockCols[i]] = blockRows[i];
    }

    // Construct a set of rows affected and see if any are filled
    std::set<int> rowSet(blockRows.begin(), blockRows.end());

    for (auto &row : rowSet) {
        if (rows[row]->isRowFilled()) clearRow(row);
    }

    return true;
}
