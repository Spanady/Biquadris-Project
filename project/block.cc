#include "block.h"
#include <vector>
#include <memory>
#include "row.h"
#include "cell.h"

void Block::makeHeavy() { heavy = true; }
void Block::makeNotHeavy() { heavy = false; }
bool Block::isHeavy() { return heavy; }
void Block::addOccupiedCells(std::shared_ptr<Cell> c) { occupiedCells.emplace_back(c); }
