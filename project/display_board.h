#ifndef DISPLAY_BOARD
#define DISPLAY_BOARD 

#include "constants.h"

class DisplayBoard {

    protected:
        std::vector<std::vector<blockType>> display;

    public:
        DisplayBoard();
        ~DisplayBoard() = default;

        /**
         * @brief Notify function called by a cell on the DisplayBoard Observer
         * 
         * @param _type the new type of the cell at row and col
         * @param _row, _col the row and column of the cell
         */
        void cellUpdate(blockType _type, int _row, int _col);
        void blind();

        virtual void updateDisplay() = 0;
};

#endif
