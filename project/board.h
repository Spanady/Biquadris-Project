#ifndef BOARD
#define BOARD

#include "cell.h"
#include "row.h"
#include "constants.h"
#include <set>

class Board {

    std::vector<std::shared_ptr<Row>> rows{BOARD_HEIGHT + 3};
    std::vector<int> colHeights{BOARD_WIDTH};

    /**
     * @brief Empties the row specified and moves that row to the top of the board (moves blocks above down one unit)
     * 
     * @param row the index of the row being cleared (where 0 is the 1st row)
     */
    void clearRow(const int row);

    /**
     * @brief Wrapped by addBlock() to take in the rows, cols, and type of the Cells in blockData and attempt to place the Cells into the board
     * 
     * @param blockRows, blockCols the vectors of Cell coordinates of the Block attempting to be placed 
     * @param type the type of Block being placed
     * @return true if the Cells were placed succesfully
     * @return false otherwise
     * 
     * @note type != blockType::NONE (returns false without placing the Cells)
     */
    bool _addBlock(const std::vector<int> &blockRows, const std::vector<int> &blockCols, const blockType type);

    /**
     * @brief Helper to _addBlock() to check if a Block can be placed at position specified
     * 
     * @param blockRows, blockCols the vectors of Cell coordinates of the Block attempting to be placed 
     * @return true if the Block can be placed
     * @return false otherwise
     */
    bool canDrop(const std::vector<int> &blockRows, const std::vector<int> &blockCols);

    public:
        Board();
        ~Board();

        /**
         * @brief Get the height of a column
         * 
         * @param col the column index between 0 and BOARD_WIDTH - 1
         * @return the current height of the column, or -1 if invalid column
         */
        int getHeight(const int col);

        /**
         * @brief Checks if the board is in a losing position (at least one column past BOARD_HIEGHT)
         * 
         * @return true if the board is in a losing position
         * @return false otherwise
         * 
         * @note this method should be called by Game after every player move
         */
        bool getisLost();
        
        /**
         * @brief Attempts to add a Block to the board if blockData is valid
         * 
         * @param blockData the Cells of the Block to be placed
         * @return true if the block was placed succesfully
         * @return false otherwise
         * 
         * @relatesalso _addBlock()
         * @note blockData is valid if Cells specified are not already occupied or underneath an occupied cell,
         *       and if the Cells' blockType is not NONE
         */
        bool addBlock(const std::vector<std::unique_ptr<Cell>> blockData);

        /**
         * @brief Resets the board by setting all Cells in each Row empty, and resetting the colHeights vector
         */
        void reset();
        
};

#endif
