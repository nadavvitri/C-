#ifndef EX2_BISHOP_H
#define EX2_BISHOP_H

#include "Piece.h"

/**
 * Class represent a Bishop in chess game
 */
class Bishop: public Piece
{
public:
    /**
     * Constructor
     * @param xPos piece x axis number (row number in table).
     * @param yPos piece y axis number (column number in table).
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     */
    Bishop(int x, int y, int player): Piece(x, y, player, "\u265D", "Bishop"){};

    /**
     * Destructor
     */
    ~Bishop() override = default;

    /**
     * Check if the wanted moving is match the rules of bishop.
     * @param x new x position.
     * @param y new y position.
     * @param player represent to who player the piece belong (0 if white, 1 if to the black).
     * @return true if move match the rules of piece, else false
     */
    bool move(int x, int y) const override;
};


#endif //EX2_BISHOP_H
