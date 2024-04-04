#include "zblock.h"
#include <vector>
#include <memory>
#include "row.h"
#include "cell.h"

// Constructor
Zblock::Zblock() {}

void Zblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/leftmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/leftmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/leftmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Fourth top/leftmost cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    if (pos == FACEUP) {
        // Set the new cells
        (theGrid[x + 1]->(*rowData[y + 1])).setBlock(blockType::Z);

        (theGrid[x1]->(*rowData[y1])).setBlock(blockType::Z);

        (theGrid[x2 - 1]->(*rowData[y2 + 1])).setBlock(blockType::Z);

        (theGrid[x3 - 2]->(*rowData[y3])).setBlock(blockType::Z);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 1]->(rowData[y + 1]));
        occupiedCells[1] = (theGrid[x1]->(rowData[y1]));
        occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2 + 1]));
        occupiedCells[3] = (theGrid[x3 - 2]->(rowData[y3]));

        // Set the new position
        pos = FACERIGHT;
    } else if (pos == FACERIGHT) {
        // Set the new cells
        (theGrid[x - 1]->(*rowData[y])).setBlock(blockType::Z);

        (theGrid[x1]->(*rowData[y1 + 1])).setBlock(blockType::Z);

        (theGrid[x2 + 1]->(*rowData[y2])).setBlock(blockType::Z);

        (theGrid[x3 + 2]->(*rowData[y3 + 1])).setBlock(blockType::Z);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
        occupiedCells[3] = (theGrid[x3 + 2]->(rowData[y3 + 1]));

        // Set the new position
        pos = FACEDOWN;
    } else if (pos == FACEDOWN) {
        // Set the new cells
        (theGrid[x + 2]->(*rowData[y])).setBlock(blockType::Z);

        (theGrid[x1 + 1]->(*rowData[y1 - 1])).setBlock(blockType::Z);

        (theGrid[x2]->(*rowData[y2])).setBlock(blockType::Z);

        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setBlock(blockType::Z);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 2]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2]));
        occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3 - 1]));

        // Set the new position
        pos = FACELEFT;
    } else if (pos == FACELEFT) {
        // Set the new cells
        (theGrid[x - 2]->(*rowData[y - 1])).setBlock(blockType::Z);

        (theGrid[x1 - 1]->(*rowData[y1])).setBlock(blockType::Z);

        (theGrid[x2]->(*rowData[y2 - 1])).setBlock(blockType::Z);

        (theGrid[x3 + 1]->(*rowData[y3])).setBlock(blockType::Z);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 2]->(rowData[y - 1]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
        occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

        // Set the new position
        pos = FACEUP;
    }
}

void Zblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    rotateCW(theGrid);
    rotateCW(theGrid);
    rotateCW(theGrid);
}

void Zblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/leftmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/leftmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/leftmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Fourth top/leftmost cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x]->(*rowData[y - 1])).setBlock(blockType::Z);

    (theGrid[x1]->(*rowData[y1 - 1])).ssetBlock(blockType::Z);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(blockType::Z);

    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(blockType::Z);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Zblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/leftmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/leftmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/leftmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Fourth top/leftmost cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x - 1]->(*rowData[y])).setBlock(blockType::Z);

    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(blockType::Z);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(blockType::Z);

    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(blockType::Z);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown(theGrid);
}

void Zblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/leftmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/leftmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/leftmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Fourth top/leftmost cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x + 1]->(*rowData[y])).setBlock(blockType::Z);

    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(blockType::Z);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(blockType::Z);

    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(blockType::Z);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown(theGrid);
}

void Zblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {

}

