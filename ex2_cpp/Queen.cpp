#include "Queen.h"

/**
 * Check if the wanted moving is match the rules of queen.
 * @param x new x position.
 * @param y new y position.
 * @return true if move match the rules of piece, else false
 */
bool Queen::move(int x, int y) const
{
    return !(this->getX() != x and this->getY() != y) or
            ((abs(this->getX() - x) - abs(this->getY() - y) == 0) and this->getX() != x);
}
