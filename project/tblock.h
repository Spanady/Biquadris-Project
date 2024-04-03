#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"
#include "row.h"
#include <vector>
#include "string"
#include <memory>

class Tblock : public Block {
    std::string pos; // Is either "upright", "upsidedown", "faceright", "faceleft"
    // faceright and faceleft are when it is sideways, based on the protruding cell
    public:
        Tblock(); // Constructor
        void rotateCW(std::vector<std::shared_ptr<Row>> theGrid) override;
        void rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) override;

        void moveDown(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveLeft(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveRight(std::vector<std::shared_ptr<Row>> theGrid) override;
        void drop(std::vector<std::shared_ptr<Row>> theGrid) override;
};
