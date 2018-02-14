#ifndef EX2_ROOK_H
#define EX2_ROOK_H

#include "Piece.h"

/**
 * Class represent a Rook in chess game
 */
class Rook: public Piece
{
private:
    bool _moved = false; // flag to check if rook moved already (can do or can't castling)
public:
    /**
     * Constructor
     * @param xPos piece x axis number (row number in table).
     * @param yPos piece y axis number (column number in table).
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     */
    Rook(int x, int y, int player): Piece(x, y, player, "\u265C", "Rook"){};

    /**
     * Destructor
     */
    ~Rook() override = default;

    /**
     * Check if the wanted moving is match the rules of rook.
     * @param x new x position.
     * @param y new y position.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if move match the rules of piece, else false
     */
    bool move(int x, int y) const override;

    /**
     * Check if rook moved before.
     * @return true if the piece moved already, else false
     */
    bool movedBefore() const override;

    /**
     * Setter the flag to true if rook moved.
     */
    void setMoved() override;
};


#endif //EX2_ROOK_H
