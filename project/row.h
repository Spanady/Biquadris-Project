#ifndef ROW
#define ROW

#include "cell.h"
#include "constants.h"

class Row {
    std::vector<std::shared_ptr<Cell>> rowData{BOARD_WIDTH}; ///< vector of Cells in the row
    int filledCells; ///< number of Cells that are filled
    int row;

    public:
        Row(int _row);
        ~Row();

        /**
         * @brief Checks if the row is completely filled
         * 
         * @return true if row is filled
         * @return false otherwise
         */
        bool isRowFilled();

        bool isCellFilled(const int col);

        /**
         * @brief Set the Cell Type object
         * 
         * @param col 
         * @param type 
         * @return true 
         * @return false 
         */
        bool setCellType(const int col, blockType type);

        /**
         * @brief sets all Cells in the row back to blank
         */
        void clear();
};

#endif
