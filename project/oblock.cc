#include "oblock.h"
#include <vector>
#include "row.h"
#include "cell.h"

// Constructor
Oblock::Oblock() {}

void Oblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Do nothing, this block is a square
}

void Oblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Do nothing, this block is a square
}

void Oblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol();
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol();
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol();
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol();
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x]->(*rowData[y - 1])).setBlock(blockType::O);

    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(blockType::O);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(blockType::O);

    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(blockType::O);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Oblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol();
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol();
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol();
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol();
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x - 1]->(*rowData[y])).setBlock(blockType::O);

    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(blockType::O);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(blockType::O);

    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(blockType::O);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown(std::vector<std::shared_ptr<Row>> theGrid);
}

void Oblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol();
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol();
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol();
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol();
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x + 1]->(*rowData[y])).setBlock(blockType::O);

    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(blockType::O);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(blockType::O);

    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(blockType::O);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown(std::vector<std::shared_ptr<Row>> theGrid);
}

void Oblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {

}
