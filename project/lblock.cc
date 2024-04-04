#include "lblock.h"
#include <vector>
#include <memory>
#include "row.h"
#include "cell.h"

// Constructor
Lblock::Lblock() {}

void Lblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/rightmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/rightmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/rightmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Protruding cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    if (pos = FACEUP) {
        // Set the new cells
        (theGrid[x]->(*rowData[y + 2])).setBlock(blockType::L);

        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setBlock(blockType::L);

        (theGrid[x2 - 2]->(*rowData[y2])).setBlock(blockType::L);

        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setBlock(blockType::L);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y + 2]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2 - 2]->(rowData[y2]));
        occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3 - 1]));

        // Set the new position
        pos = FACERIGHT;
    } else if (pos == FACERIGHT) {
        // Set the new cells
        (theGrid[x + 2]->(*rowData[y])).setBlock(blockType::L);

        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setBlock(blockType::L);

        (theGrid[x2]->(*rowData[y2 + 2])).setBlock(blockType::L);

        (theGrid[x3 - 1]->(*rowData[y3 + 1])).setBlock(blockType::L);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 2]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2 + 2]));
        occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3 + 1]));

        // Set the new position
        pos = FACEDOWN;
    } else if (pos == FACEDOWN) {
        // Set the new cells
        (theGrid[x]->(*rowData[y])).setBlock(blockType::L);

        (theGrid[x1 + 1]->(*rowData[y1 - 1])).setBlock(blockType::L);

        (theGrid[x2 + 2]->(*rowData[y2 - 2])).setBlock(blockType::L);

        (theGrid[x3 + 1]->(*rowData[y3 + 1])).setBlock(blockType::L);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 + 2]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3 + 1]));

        // Set the new position
        pos = FACELEFT;
    } else if (pos == FACELEFT) {
        // Set the new cells
        (theGrid[x - 2]->(*rowData[y + 2])).setBlock(blockType::L);

        (theGrid[x1 - 1]->(*rowData[y1 - 1])).setBlock(blockType::L);

        (theGrid[x2]->(*rowData[y2 - 2])).setBlock(blockType::L);

        (theGrid[x3 + 1]->(*rowData[y3 - 1])).setBlock(blockType::L);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 2]->(rowData[y + 2]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3 - 1]));

        // Set the new position
        pos = FACEUP;
    }
}

void Lblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
}

void Lblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/rightmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/rightmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/rightmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Protruding cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x]->(*rowData[y - 1])).setBlock(blockType::L);

    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(blockType::L);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(blockType::L);

    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(blockType::L);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Lblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/rightmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/rightmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/rightmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Protruding cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x - 1]->(*rowData[y])).setBlock(blockType::L);

    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(blockType::L);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(blockType::L);

    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(blockType::L);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown(std::vector<std::shared_ptr<Row>> theGrid);
}

void Lblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top/rightmost cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top/rightmost cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top/rightmost cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Protruding cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();

    // Set each new cell
    (theGrid[x + 1]->(*rowData[y])).setBlock(blockType::L);

    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(blockType::L);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(blockType::L);

    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(blockType::L);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown(std::vector<std::shared_ptr<Row>> theGrid);
}

void Lblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {

}

