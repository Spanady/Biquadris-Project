#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"
#include "row.h"
#include <vector>
#include <memory>

class Oblock : public Block {
    public:
        Oblock(); // Constructor
        void rotateCW(std::vector<std::shared_ptr<Row>> theGrid) override;
        void rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) override;

        void moveDown(std::vector<std::shared_ptr<Row>> theGrid) override;
        void modeLeft(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveRight(std::vector<std::shared_ptr<Row>> theGrid) override;
        void drop(std::vector<std::shared_ptr<Row>> theGrid) override;
};
