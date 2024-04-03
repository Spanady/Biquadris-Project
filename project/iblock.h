#ifndef __IBLOCK_H__
#define __IBLOCK_H__
#include "block.h"
#include "row.h"
#include <vector>
#include "string"
#include <memory>

class Iblock : public Block {
    std::string pos; // Is either "uprightl", "uprightr", "sidewaysd", "sidewaysu"
    // Based on if the Iblock (which is a line) is in position | or _
    public:
        Iblock(); // Constructor
        void rotateCW(std::vector<std::shared_ptr<Row>> theGrid) override;
        void rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) override;

        void moveDown(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveLeft(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveRight(std::vector<std::shared_ptr<Row>> theGrid) override;
};
