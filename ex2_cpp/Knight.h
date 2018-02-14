#ifndef EX2_KNIGHT_H
#define EX2_KNIGHT_H


#include "Piece.h"

/**
 * Class represent a Knight in chess game
 */
class Knight: public Piece
{
public:
    /**
     * Constructor
     * @param xPos piece x axis number (row number in table).
     * @param yPos piece y axis number (column number in table).
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     */
    Knight(int x, int y, int player): Piece(x, y, player, "\u265E", "Knight"){};

    /**
     * Destructor
     */
    ~Knight() override = default;

    /**
     * Check if the wanted moving is match the rules of knight.
     * @param x new x position.
     * @param y new y position.
     * @return true if move match the rules of piece, else false
     */
    bool move(int x, int y) const override;
};


#endif //EX2_KNIGHT_H
