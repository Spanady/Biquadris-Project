#include "lblock.h"
#include <vector>
#include "row.h"
#include "cell.h"

// Constructor
Lblock::Lblock() {}

void Lblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getX(); // Top/rightmost cell
    int y = (*occupiedCells[0]).getY();

    int x1 = (*occupiedCells[1]).getX(); // Second top/rightmost cell
    int y1 = (*occupiedCells[1]).getY();

    int x2 = (*occupiedCells[2]).getX(); // Third top/rightmost cell
    int y2 = (*occupiedCells[2]).getY();

    int x3 = (*occupiedCells[3]).getX(); // Protruding cell
    int y3 = (*occupiedCells[3]).getY();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).makeEmpty();
    (theGrid[x1]->(*rowData[y1])).makeEmpty();
    (theGrid[x2]->(*rowData[y2])).makeEmpty();
    (theGrid[x3]->(*rowData[y3])).makeEmpty();

    if (pos = "faceup") {
        // Set the new cells
        (theGrid[x]->(*rowData[y + 2])).setS("L");
        (theGrid[x]->(*rowData[y + 2])).setBlock(this);
        (theGrid[x]->(*rowData[y + 2])).setFilled(true);

        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setS("L");
        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setBlock(this);
        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setFilled(true);

        (theGrid[x2 - 2]->(*rowData[y2])).setS("L");
        (theGrid[x2 - 2]->(*rowData[y2])).setBlock(this);
        (theGrid[x2 - 2]->(*rowData[y2])).setFilled(true);

        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setS("L");
        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setBlock(this);
        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y + 2]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2 - 2]->(rowData[y2]));
        occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3 - 1]));

        // Set the new position
        pos = "faceright";
    } else if ("faceright") {
        // Set the new cells
        (theGrid[x + 2]->(*rowData[y])).setS("L");
        (theGrid[x + 2]->(*rowData[y])).setBlock(this);
        (theGrid[x + 2]->(*rowData[y])).setFilled(true);

        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setS("L");
        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setBlock(this);
        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setFilled(true);

        (theGrid[x2]->(*rowData[y2 + 2])).setS("L");
        (theGrid[x2]->(*rowData[y2 + 2])).setBlock(this);
        (theGrid[x2]->(*rowData[y2 + 2])).setFilled(true);

        (theGrid[x3 - 1]->(*rowData[y3 + 1])).setS("L");
        (theGrid[x3 - 1]->(*rowData[y3 + 1])).setBlock(this);
        (theGrid[x3 - 1]->(*rowData[y3 + 1])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 2]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2 + 2]));
        occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3 + 1]));

        // Set the new position
        pos = "facedown";
    } else if ("facedown") {
        // Set the new cells
        (theGrid[x]->(*rowData[y])).setS("L");
        (theGrid[x]->(*rowData[y])).setBlock(this);
        (theGrid[x]->(*rowData[y])).setFilled(true);

        (theGrid[x1 + 1]->(*rowData[y1 - 1])).setS("L");
        (theGrid[x1 + 1]->(*rowData[y1 - 1])).setBlock(this);
        (theGrid[x1 + 1]->(*rowData[y1 - 1])).setFilled(true);

        (theGrid[x2 + 2]->(*rowData[y2 - 2])).setS("L");
        (theGrid[x2 + 2]->(*rowData[y2 - 2])).setBlock(this);
        (theGrid[x2 + 2]->(*rowData[y2 - 2])).setFilled(true);

        (theGrid[x3 + 1]->(*rowData[y3 + 1])).setS("L");
        (theGrid[x3 + 1]->(*rowData[y3 + 1])).setBlock(this);
        (theGrid[x3 + 1]->(*rowData[y3 + 1])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 + 2]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3 + 1]));

        // Set the new position
        pos = "faceleft";
    } else if ("faceleft") {
        // Set the new cells
        (theGrid[x - 2]->(*rowData[y + 2])).setS("L");
        (theGrid[x - 2]->(*rowData[y + 2])).setBlock(this);
        (theGrid[x - 2]->(*rowData[y + 2])).setFilled(true);

        (theGrid[x1 - 1]->(*rowData[y1 - 1])).setS("L");
        (theGrid[x1 - 1]->(*rowData[y1 - 1])).setBlock(this);
        (theGrid[x1 - 1]->(*rowData[y1 - 1])).setFilled(true);

        (theGrid[x2]->(*rowData[y2 - 2])).setS("L");
        (theGrid[x2]->(*rowData[y2 - 2])).setBlock(this);
        (theGrid[x2]->(*rowData[y2 - 2])).setFilled(true);

        (theGrid[x3 + 1]->(*rowData[y3 - 1])).setS("L");
        (theGrid[x3 + 1]->(*rowData[y3 - 1])).setBlock(this);
        (theGrid[x3 + 1]->(*rowData[y3 - 1])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 2]->(rowData[y + 2]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3 - 1]));

        // Set the new position
        pos = "faceup";
    }
}

void Lblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
}

void Lblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x]->(*rowData[y - 1])).setS("L");
    (theGrid[x]->(*rowData[y - 1])).setBlock(this);
    (theGrid[x]->(*rowData[y - 1])).setFilled(true);

    (theGrid[x1]->(*rowData[y1 - 1])).setS("L");
    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(this);
    (theGrid[x1]->(*rowData[y1 - 1])).setFilled(true);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setS("L");
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(this);
    (theGrid[x2]->(*rowData[y2 - 1])).setFilled(true);

    (theGrid[x3]->(*rowData[y3 - 1])).setS("L");
    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(this);
    (theGrid[x3]->(*rowData[y3 - 1])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Lblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x - 1]->(*rowData[y])).setS("L");
    (theGrid[x - 1]->(*rowData[y])).setBlock(this);
    (theGrid[x - 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 - 1]->(*rowData[y1])).setS("L");
    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 - 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setS("L");
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 - 1]->(*rowData[y2])).setFilled(true);

    (theGrid[x3 - 1]->(*rowData[y3])).setS("L");
    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 - 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Lblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x + 1]->(*rowData[y])).setS("L");
    (theGrid[x + 1]->(*rowData[y])).setBlock(this);
    (theGrid[x + 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 + 1]->(*rowData[y1])).setS("L");
    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 + 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setS("L");
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 + 1]->(*rowData[y2])).setFilled(true);
    (theGrid[x3 + 1]->(*rowData[y3])).setS("L");
    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 + 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Lblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {

}

