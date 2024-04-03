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
    int x = (*occupiedCells[0]).getX();
    int y = (*occupiedCells[0]).getY();

    int x1 = (*occupiedCells[1]).getX();
    int y1 = (*occupiedCells[1]).getY();

    int x2 = (*occupiedCells[2]).getX();
    int y2 = (*occupiedCells[2]).getY();

    int x3 = (*occupiedCells[3]).getX();
    int y3 = (*occupiedCells[3]).getY();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).makeEmpty();
    (theGrid[x1]->(*rowData[y1])).makeEmpty();
    (theGrid[x2]->(*rowData[y2])).makeEmpty();
    (theGrid[x3]->(*rowData[y3])).makeEmpty();

    // Set each new cell
    (theGrid[x]->(*rowData[y - 1])).setS("O");
    (theGrid[x]->(*rowData[y - 1])).setBlock(this);
    (theGrid[x]->(*rowData[y - 1])).setFilled(true);

    (theGrid[x1]->(*rowData[y1 - 1])).setS("O");
    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(this);
    (theGrid[x1]->(*rowData[y1 - 1])).setFilled(true);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setS("O");
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(this);
    (theGrid[x2]->(*rowData[y2 - 1])).setFilled(true);

    (theGrid[x3]->(*rowData[y3 - 1])).setS("O");
    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(this);
    (theGrid[x3]->(*rowData[y3 - 1])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Oblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getX();
    int y = (*occupiedCells[0]).getY();

    int x1 = (*occupiedCells[1]).getX();
    int y1 = (*occupiedCells[1]).getY();

    int x2 = (*occupiedCells[2]).getX();
    int y2 = (*occupiedCells[2]).getY();

    int x3 = (*occupiedCells[3]).getX();
    int y3 = (*occupiedCells[3]).getY();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).makeEmpty();
    (theGrid[x1]->(*rowData[y1])).makeEmpty();
    (theGrid[x2]->(*rowData[y2])).makeEmpty();
    (theGrid[x3]->(*rowData[y3])).makeEmpty();

    // Set each new cell
    (theGrid[x - 1]->(*rowData[y])).setS("O");
    (theGrid[x - 1]->(*rowData[y])).setBlock(this);
    (theGrid[x - 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 - 1]->(*rowData[y1])).setS("O");
    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 - 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setS("O");
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 - 1]->(*rowData[y2])).setFilled(true);

    (theGrid[x3 - 1]->(*rowData[y3])).setS("O");
    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 - 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Oblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getX();
    int y = (*occupiedCells[0]).getY();

    int x1 = (*occupiedCells[1]).getX();
    int y1 = (*occupiedCells[1]).getY();

    int x2 = (*occupiedCells[2]).getX();
    int y2 = (*occupiedCells[2]).getY();

    int x3 = (*occupiedCells[3]).getX();
    int y3 = (*occupiedCells[3]).getY();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).makeEmpty();
    (theGrid[x1]->(*rowData[y1])).makeEmpty();
    (theGrid[x2]->(*rowData[y2])).makeEmpty();
    (theGrid[x3]->(*rowData[y3])).makeEmpty();

    // Set each new cell
    (theGrid[x + 1]->(*rowData[y])).setS("O");
    (theGrid[x + 1]->(*rowData[y])).setBlock(this);
    (theGrid[x + 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 + 1]->(*rowData[y1])).setS("O");
    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 + 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setS("O");
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 + 1]->(*rowData[y2])).setFilled(true);
    (theGrid[x3 + 1]->(*rowData[y3])).setS("O");
    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 + 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Oblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {

}
