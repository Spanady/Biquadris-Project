#ifndef __LBLOCK_H__
#define __LBLOCK_H__
#include "block.h"
#include "row.h"
#include <vector>
#include <memory>

class Lblock : public Block {
    blockPos pos;
    public:
        Lblock(); // Constructor
        void rotateCW(std::vector<std::shared_ptr<Row>> theGrid) override;
        void rotateCCW(std::vector<std::shared_ptr<Row>> theGrid) override;

        void moveDown(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveLeft(std::vector<std::shared_ptr<Row>> theGrid) override;
        void moveRight(std::vector<std::shared_ptr<Row>> theGrid) override;
        void drop(std::vector<std::shared_ptr<Row>> theGrid) override;
};

#endif
