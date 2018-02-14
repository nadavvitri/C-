#ifndef EX2_KING_H
#define EX2_KING_H


#include "Piece.h"

/**
 * Class represent a King in chess game
 */
class King: public Piece
{
private:
    bool _moved = false; // flag to check if king moved already (can do or can't castling)
public:
    /**
     * Constructor
     * @param xPos piece x axis number (row number in table).
     * @param yPos piece y axis number (column number in table).
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     */
    King(int x, int y, int player): Piece(x, y, player, "\u265A", "King"){};
    /**
     * Destructor
     */
    ~King() override = default;

    /**
     * Check if the wanted moving is match the rules of king.
     * @param x new x position.
     * @param y new y position.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if move match the rules of piece, else false
     */
    bool move(int x, int y) const override;

    /**
     * Check if king moved before.
     * @return true if the piece moved already, else false
     */
    bool movedBefore() const override;

    /**
     * Setter the flag to true if king moved.
     */
    void setMoved() override;
};


#endif //EX2_KING_H
