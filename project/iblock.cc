#include "iblock.h"
#include <vector>
#include "row.h"
#include "cell.h"

Iblock::Iblock() {}

Iblock::rotateCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Get the coordinates for all the cells the block occupies
    int x = (*occupiedCells[0]).getX(); // Top cell
    int y = (*occupiedCells[0]).getY();

    int x1 = (*occupiedCells[1]).getX(); // Second top cell
    int y1 = (*occupiedCells[1]).getY();

    int x2 = (*occupiedCells[2]).getX(); // Third top cell
    int y2 = (*occupiedCells[2]).getY();

    int x3 = (*occupiedCells[3]).getX(); // Bottom cell
    int y3 = (*occupiedCells[3]).getY();

    // Set all the old cells to empty
    (theGrid[x]->(*rowData[y])).makeEmpty();
    (theGrid[x1]->(*rowData[y1])).makeEmpty();
    (theGrid[x2]->(*rowData[y2])).makeEmpty();
    (theGrid[x3]->(*rowData[y3])).makeEmpty();
    
    if (pos == "uprightl") {
        // Set the new cells
        (theGrid[x]->(*rowData[y])).setS("I");
        (theGrid[x]->(*rowData[y])).setBlock(this);
        (theGrid[x]->(*rowData[y])).setFilled(true);

        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setS("I");
        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setBlock(this);
        (theGrid[x1 + 1]->(*rowData[y1 + 1])).setFilled(true);

        (theGrid[x2 + 2]->(*rowData[y2 + 2])).setS("I");
        (theGrid[x2 + 2]->(*rowData[y2 + 2])).setBlock(this);
        (theGrid[x2 + 2]->(*rowData[y2 + 2])).setFilled(true);

        (theGrid[x3 + 3]->(*rowData[y3 + 3])).setS("I");
        (theGrid[x3 + 3]->(*rowData[y3 + 3])).setBlock(this);
        (theGrid[x3 + 3]->(*rowData[y3 + 3])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1 + 1]));
        occupiedCells[2] = (theGrid[x2 + 2]->(rowData[y2 + 2]));
        occupiedCells[3] = (theGrid[x3 + 3]->(rowData[y3 + 3]));

        // Set the new position
        pos = "sidewaysu";

    } else if (pos == "sidewaysu") {
        // Set the new cells
        (theGrid[x + 3]->(*rowData[y])).setS("I");
        (theGrid[x + 3]->(*rowData[y])).setBlock(this);
        (theGrid[x + 3]->(*rowData[y])).setFilled(true);

        (theGrid[x1 + 2]->(*rowData[y1 - 1])).setS("I");
        (theGrid[x1 + 2]->(*rowData[y1 - 1])).setBlock(this);
        (theGrid[x1 + 2]->(*rowData[y1 - 1])).setFilled(true);

        (theGrid[x2 + 1]->(*rowData[y2 - 2])).setS("I");
        (theGrid[x2 + 1]->(*rowData[y2 - 2])).setBlock(this);
        (theGrid[x2 + 1]->(*rowData[y2 - 2])).setFilled(true);

        (theGrid[x3]->(*rowData[y3 - 3])).setS("I");
        (theGrid[x3]->(*rowData[y3 - 3])).setBlock(this);
        (theGrid[x3]->(*rowData[y3 - 3])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x + 3]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 + 2]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 3]));

        // Set the new position 
        pos = "uprightr";


    } else if (pos == "uprightr") {
        // Set the new cells
        (theGrid[x - 3]->(*rowData[y])).setS("I");
        (theGrid[x - 3]->(*rowData[y])).setBlock(this);
        (theGrid[x - 3]->(*rowData[y])).setFilled(true);

        (theGrid[x1 - 2]->(*rowData[y1 - 1])).setS("I");
        (theGrid[x1 - 2]->(*rowData[y1 - 1])).setBlock(this);
        (theGrid[x1 - 2]->(*rowData[y1 - 1])).setFilled(true);

        (theGrid[x2 - 1]->(*rowData[y2 - 2])).setS("I");
        (theGrid[x2 - 1]->(*rowData[y2 - 2])).setBlock(this);
        (theGrid[x2 - 1]->(*rowData[y2 - 2])).setFilled(true);

        (theGrid[x3]->(*rowData[y3 - 3])).setS("I");
        (theGrid[x3]->(*rowData[y3 - 3])).setBlock(this);
        (theGrid[x3]->(*rowData[y3 - 3])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x - 3]->(rowData[y]));
        occupiedCells[1] = (theGrid[x1 - 2]->(rowData[y1 - 1]));
        occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2 - 2]));
        occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 3]));

        // Set the new position 
        pos = "sidewaysd";
    } else if (pos == "sidewaysd") {
        // Set the new cells
        (theGrid[x]->(*rowData[y + 3])).setS("I");
        (theGrid[x]->(*rowData[y + 3])).setBlock(this);
        (theGrid[x]->(*rowData[y + 3])).setFilled(true);

        (theGrid[x1 - 1]->(*rowData[y1 + 2])).setS("I");
        (theGrid[x1 - 1]->(*rowData[y1 + 2])).setBlock(this);
        (theGrid[x1 - 1]->(*rowData[y1 + 2])).setFilled(true);

        (theGrid[x2 - 2]->(*rowData[y2 + 1])).setS("I");
        (theGrid[x2 - 2]->(*rowData[y2 + 1])).setBlock(this);
        (theGrid[x2 - 2]->(*rowData[y2 + 1])).setFilled(true);

        (theGrid[x3 - 3]->(*rowData[y3])).setS("I");
        (theGrid[x3 - 3]->(*rowData[y3])).setBlock(this);
        (theGrid[x3 - 3]->(*rowData[y3])).setFilled(true);

        // Set the new occupied cells
        occupiedCells[0] = (theGrid[x]->(rowData[y + 3]));
        occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1 + 2]));
        occupiedCells[2] = (theGrid[x2 - 2]->(rowData[y2 + 1]));
        occupiedCells[3] = (theGrid[x3 - 3]->(rowData[y3]));

        // Set the new position
        pos = "uprightl";
    }
}

Iblock::rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) {
    // Rotate the block clockwise 3 times, has the same effect as rotating
    // it counter-clockwise once
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
    rotateCW(std::vector<std::shared_ptr<Row>> theGrid);
}

void Iblock::moveDown(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x]->(*rowData[y - 1])).setS("I");
    (theGrid[x]->(*rowData[y - 1])).setBlock(this);
    (theGrid[x]->(*rowData[y - 1])).setFilled(true);

    (theGrid[x1]->(*rowData[y1 - 1])).setS("I");
    (theGrid[x1]->(*rowData[y1 - 1])).setBlock(this);
    (theGrid[x1]->(*rowData[y1 - 1])).setFilled(true);
    
    (theGrid[x2]->(*rowData[y2 - 1])).setS("I");
    (theGrid[x2]->(*rowData[y2 - 1])).setBlock(this);
    (theGrid[x2]->(*rowData[y2 - 1])).setFilled(true);

    (theGrid[x3]->(*rowData[y3 - 1])).setS("I");
    (theGrid[x3]->(*rowData[y3 - 1])).setBlock(this);
    (theGrid[x3]->(*rowData[y3 - 1])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x]->(rowData[y - 1]));
    occupiedCells[1] = (theGrid[x1]->(rowData[y1 - 1]));
    occupiedCells[2] = (theGrid[x2]->(rowData[y2 - 1]));
    occupiedCells[3] = (theGrid[x3]->(rowData[y3 - 1]));
}

void Iblock::moveLeft(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x - 1]->(*rowData[y])).setS("I");
    (theGrid[x - 1]->(*rowData[y])).setBlock(this);
    (theGrid[x - 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 - 1]->(*rowData[y1])).setS("I");
    (theGrid[x1 - 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 - 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 - 1]->(*rowData[y2])).setS("I");
    (theGrid[x2 - 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 - 1]->(*rowData[y2])).setFilled(true);

    (theGrid[x3 - 1]->(*rowData[y3])).setS("I");
    (theGrid[x3 - 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 - 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x - 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 - 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 - 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 - 1]->(rowData[y3]));

    if (heavy) moveDown();
}

void Iblock::moveRight(std::vector<std::shared_ptr<Row>> theGrid) {
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
    (theGrid[x + 1]->(*rowData[y])).setS("I");
    (theGrid[x + 1]->(*rowData[y])).setBlock(this);
    (theGrid[x + 1]->(*rowData[y])).setFilled(true);

    (theGrid[x1 + 1]->(*rowData[y1])).setS("I");
    (theGrid[x1 + 1]->(*rowData[y1])).setBlock(this);
    (theGrid[x1 + 1]->(*rowData[y1])).setFilled(true);
    
    (theGrid[x2 + 1]->(*rowData[y2])).setS("I");
    (theGrid[x2 + 1]->(*rowData[y2])).setBlock(this);
    (theGrid[x2 + 1]->(*rowData[y2])).setFilled(true);
    
    (theGrid[x3 + 1]->(*rowData[y3])).setS("I");
    (theGrid[x3 + 1]->(*rowData[y3])).setBlock(this);
    (theGrid[x3 + 1]->(*rowData[y3])).setFilled(true);

    // Set the new occupied Cells
    occupiedCells[0] = (theGrid[x + 1]->(rowData[y]));
    occupiedCells[1] = (theGrid[x1 + 1]->(rowData[y1]));
    occupiedCells[2] = (theGrid[x2 + 1]->(rowData[y2]));
    occupiedCells[3] = (theGrid[x3 + 1]->(rowData[y3]));

    if (heavy) moveDown();
}


Iblock::drop(std::vector<std::shared_ptr<Row>> theGrid) {
    if (pos == "uprightr" || pos == "uprightl") {
        
    } else if (pos == "sidewaysu" || pos == "sidewaysd") {

    }
}
