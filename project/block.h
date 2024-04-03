#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <vector>
#include "cell.h"
#include "row.h"
#include <memory>

// Designed using the factory method design pattern
// No instances of the abstract Block class will be created

class Block {
    std::vector<std::shared_ptr<Cell>> occupiedCells; // Vector of all the cells the block occupies
    bool heavy; // True if the block is heavy, false if it is not heavy (special effect)
    // string position; // Is either UPRIGHT, UPSIDEDOWN, LEFT, RIGHT


    public:
        // Rotating functions
        virtual void rotateCW(std::vector<std::shared_ptr<Row>> theGrid) = 0;
        virtual void rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) = 0;

        // Moving functions
        virtual void moveDown(std::vector<std::shared_ptr<Row>> theGrid) = 0;
        virtual void moveLeft(std::vector<std::shared_ptr<Row>> theGrid) = 0;
        virtual void moveRight(std::vector<std::shared_ptr<Row>> theGrid) = 0;
        virtual void drop(std::vector<std::shared_ptr<Row>> theGrid) = 0;
        
        void makeHeavy();
        void makeNotHeavy();
        bool isHeavy();
        void addOccupiedCells(std::shared_ptr<Cell> c);
};

#endif
