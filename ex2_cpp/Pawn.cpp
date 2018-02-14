#include "Pawn.h"

/**
 * Check if the wanted moving is match the rules of pawn.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool Pawn::move(int x, int y) const
{
    if (this->getPlayer() == BLACK_PLAYER)
    {
        return (((this->getX() == x) and ((y == this->getY() + 1) or ((this->getY() == 1) and
                (y == this->getY() + 2)))) or ((y == this->getY() + 1) and ((x == this->getX() + 1)
                or (x == this->getX() - 1))));
    }
    return (((this->getX() == x) and ((y == this->getY() - 1) or ((this->getY() == 6) and
            (y == this->getY() - 2)))) or ((y == this->getY() - 1) and ((x == this->getX() + 1)
            or (x == this->getX() - 1))));
}
