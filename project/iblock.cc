#include "iblock.h"
#include <vector>
#include "row.h"
#include "cell.h"

Iblock::Iblock() {}

void Iblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getCol(); // Top cell
    int y = (*occupiedCells[0]).getRow();

    int x1 = (*occupiedCells[1]).getCol(); // Second top cell
    int y1 = (*occupiedCells[1]).getRow();

    int x2 = (*occupiedCells[2]).getCol(); // Third top cell
    int y2 = (*occupiedCells[2]).getRow();

    int x3 = (*occupiedCells[3]).getCol(); // Bottom cell
    int y3 = (*occupiedCells[3]).getRow();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).setEmpty();
    (theGrid[x1]->(*rowData[y1])).setEmpty();
    (theGrid[x2]->(*rowData[y2])).setEmpty();
    (theGrid[x3]->(*rowData[y3])).setEmpty();
    
    if (pos == FACERIGHT) {
        // Set the new cells
        (theGrid[x]->(*rowData[y])).setBlock(blockType::I);

        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setBlock(blockType::I);

        (theGrid[x2 + 2]->(*rowData[y2 + 2])).setBlock(blockType::I);

        (theGrid[x3 + 3]->(*rowData[y3 + 3])).setBlock(blockType::I);


        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2 + 2]->(rowData[y2 + 2]));
        occupiedCells[3] = (theGrid[x3 + 3]->(rowData[y3 + 3]));

        // Set the new position
        pos = FACEDOWN;

    } else if (pos == FACEDOWN) {
        // Set the new cells
        (theGrid[x + 3]->(*rowData[y])).setBlock(blockType::I);

        (theGrid[x1 + 2]->(*rowData[y1 - 1])).setBlock(blockType::I);

        (theGrid[x2 + 1]->(*rowData[y2 - 2])).setBlock(blockType::I);

        (theGrid[x3]->(*rowData[y3 - 3])).setBlock(blockType::I);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 3]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 2]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 3]));

        // Set the new position 
        pos = FACELEFT;
    } else if (pos == FACELEFT) {
        // Set the new cells
        (theGrid[x - 3]->(*rowData[y])).setBlock(blockType::I);

        (theGrid[x1 - 2]->(*rowData[y1 - 1])).setBlock(blockType::I);

        (theGrid[x2 - 1]->(*rowData[y2 - 2])).setBlock(blockType::I);

        (theGrid[x3]->(*rowData[y3 - 3])).setBlock(blockType::I);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 3]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 - 2]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 3]));

        // Set the new position 
        pos = FACEUP;
    } else if (pos == FACEUP) {
        // Set the new cells
        (theGrid[x]->(*rowData[y + 3])).setBlock(blockType::I);

        (theGrid[x1 - 1]->(*rowData[y1 + 2])).setBlock(blockType::I);

        (theGrid[x2 - 2]->(*rowData[y2 + 1])).setBlock(blockType::I);

        (theGrid[x3 - 3]->(*rowData[y3])).setBlock(blockType::I);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y + 3]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 + 2]));
        occupiedCells[2] = (theGrid[x2 - 2]->(rowData[y2 + 1]));
        occupiedCells[3] = (theGrid[x3 - 3]->(rowData[y3]));

        // Set the new position
        pos = FACERIGHT;
    }
}

void Iblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Rotate the block clockwise 3 times, has the same effect as rotating
    // it counter-clockwise once
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
}

void Iblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x]->(*rowData[y - 1])).setBlock(blockType::I);

    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(blockType::I);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(blockType::I);

    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(blockType::I);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Iblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x - 1]->(*rowData[y])).setBlock(blockType::I);

    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(blockType::I);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(blockType::I);

    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(blockType::I);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown(std::vector<std::shared_ptr<Row>> theGrid);
}

void Iblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x + 1]->(*rowData[y])).setBlock(blockType::I);

    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(blockType::I);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(blockType::I);

    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(blockType::I);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown(std::vector<std::shared_ptr<Row>> theGrid);
}
