#include "sblock.h"
#include <vector>
#include "row.h"
#include "cell.h"

// Constructor
Sblock::Sblock() {}

void Sblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getX(); // Top/leftmost cell
    int y = (*occupiedCells[0]).getY();

    int x1 = (*occupiedCells[1]).getX(); // Second top/leftmost cell
    int y1 = (*occupiedCells[1]).getY();

    int x2 = (*occupiedCells[2]).getX(); // Third top/leftmost cell
    int y2 = (*occupiedCells[2]).getY();

    int x3 = (*occupiedCells[3]).getX(); // Fourth top/leftmost cell
    int y3 = (*occupiedCells[3]).getY();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).makeEmpty();
    (theGrid[x1]->(*rowData[y1])).makeEmpty();
    (theGrid[x2]->(*rowData[y2])).makeEmpty();
    (theGrid[x3]->(*rowData[y3])).makeEmpty();

    if (pos = "uprightd") {
        // Set the new cells
        (theGrid[x]->(*rowData[y + 2])).setS("L");
        (theGrid[x]->(*rowData[y + 2])).setBlock(this);
        (theGrid[x]->(*rowData[y + 2])).setFilled(true);

        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setS("L");
        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setBlock(this);
        (theGrid[x1 - 1]->(*rowData[y1 + 1])).setFilled(true);

        (theGrid[x2]->(*rowData[y2])).setS("L");
        (theGrid[x2]->(*rowData[y2])).setBlock(this);
        (theGrid[x2]->(*rowData[y2])).setFilled(true);

        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setS("L");
        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setBlock(this);
        (theGrid[x3 - 1]->(*rowData[y3 - 1])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y + 2]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2]));
        occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3 - 1]));

        // Set the new position
        pos = "sidewaysl";
    } else if ("sidewaysl") {
        // Set the new cells
        (theGrid[x]->(*rowData[y - 1])).setS("L");
        (theGrid[x]->(*rowData[y - 1])).setBlock(this);
        (theGrid[x]->(*rowData[y - 1])).setFilled(true);

        (theGrid[x1 + 1]->(*rowData[y1])).setS("L");
        (theGrid[x1 + 1]->(*rowData[y1])).setBlock(this);
        (theGrid[x1 + 1]->(*rowData[y1])).setFilled(true);

        (theGrid[x2]->(*rowData[y2 + 1])).setS("L");
        (theGrid[x2]->(*rowData[y2 + 1])).setBlock(this);
        (theGrid[x2]->(*rowData[y2 + 1])).setFilled(true);

        (theGrid[x3 + 1]->(*rowData[y3 + 2])).setS("L");
        (theGrid[x3 + 1]->(*rowData[y3 + 2])).setBlock(this);
        (theGrid[x3 + 1]->(*rowData[y3 + 2])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
        occupiedCells[2] = (theGrid[x2]->(rowData[y2 + 1]));
        occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3 + 2]));

        // Set the new position
        pos = "uprightu";
    } else if ("uprightu") {
        // Set the new cells
        (theGrid[x + 1]->(*rowData[y + 1])).setS("L");
        (theGrid[x + 1]->(*rowData[y + 1])).setBlock(this);
        (theGrid[x + 1]->(*rowData[y + 1])).setFilled(true);

        (theGrid[x1]->(*rowData[y1])).setS("L");
        (theGrid[x1]->(*rowData[y1])).setBlock(this);
        (theGrid[x1]->(*rowData[y1])).setFilled(true);

        (theGrid[x2 + 1]->(*rowData[y2 - 1])).setS("L");
        (theGrid[x2 + 1]->(*rowData[y2 - 1])).setBlock(this);
        (theGrid[x2 + 1]->(*rowData[y2 - 1])).setFilled(true);

        (theGrid[x3]->(*rowData[y3 - 2])).setS("L");
        (theGrid[x3]->(*rowData[y3 - 2])).setBlock(this);
        (theGrid[x3]->(*rowData[y3 - 2])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 1]->(rowData[y + 1]));
        occupiedCells[1] = (theGrid[x1]->(rowData[y1]));
        occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2 - 1]));
        occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 2]));

        // Set the new position
        pos = "sidewaysr";
    } else if ("sidewaysr") {
        // Set the new cells
        (theGrid[x - 1]->(*rowData[y - 2])).setS("L");
        (theGrid[x - 1]->(*rowData[y - 2])).setBlock(this);
        (theGrid[x - 1]->(*rowData[y - 2])).setFilled(true);

        (theGrid[x1]->(*rowData[y1 - 1])).setS("L");
        (theGrid[x1]->(*rowData[y1 - 1])).setBlock(this);
        (theGrid[x1]->(*rowData[y1 - 1])).setFilled(true);

        (theGrid[x2 - 1]->(*rowData[y2])).setS("L");
        (theGrid[x2 - 1]->(*rowData[y2])).setBlock(this);
        (theGrid[x2 - 1]->(*rowData[y2])).setFilled(true);

        (theGrid[x3]->(*rowData[y3 + 1])).setS("L");
        (theGrid[x3]->(*rowData[y3 + 1])).setBlock(this);
        (theGrid[x3]->(*rowData[y3 + 1])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 1]->(rowData[y - 2]));
        occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
        occupiedCells[3] = (theGrid[x3]->(rowData[y3 + 1]));

        // Set the new position
        pos = "uprightd";
    }
}

void Sblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    rotateCCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCCW(std::vector<std::shared_ptr<Row>> theGrid);
}

void Sblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x]->(*rowData[y - 1])).setS("S");
    (theGrid[x]->(*rowData[y - 1])).setBlock(this);
    (theGrid[x]->(*rowData[y - 1])).setFilled(true);

    (theGrid[x1]->(*rowData[y1 - 1])).setS("S");
    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(this);
    (theGrid[x1]->(*rowData[y1 - 1])).setFilled(true);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setS("S");
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(this);
    (theGrid[x2]->(*rowData[y2 - 1])).setFilled(true);

    (theGrid[x3]->(*rowData[y3 - 1])).setS("S");
    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(this);
    (theGrid[x3]->(*rowData[y3 - 1])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Sblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x - 1]->(*rowData[y])).setS("S");
    (theGrid[x - 1]->(*rowData[y])).setBlock(this);
    (theGrid[x - 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 - 1]->(*rowData[y1])).setS("S");
    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 - 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setS("S");
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 - 1]->(*rowData[y2])).setFilled(true);

    (theGrid[x3 - 1]->(*rowData[y3])).setS("S");
    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 - 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Sblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x + 1]->(*rowData[y])).setS("S");
    (theGrid[x + 1]->(*rowData[y])).setBlock(this);
    (theGrid[x + 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 + 1]->(*rowData[y1])).setS("S");
    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 + 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setS("S");
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 + 1]->(*rowData[y2])).setFilled(true);
    (theGrid[x3 + 1]->(*rowData[y3])).setS("S");
    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 + 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Sblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {

}

